*** UID:000019 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class InputEvent;

class BrowserPane : public DialogPane
{
public:
    BrowserPane(const wchar_t *title, int dialogConfigId, bool modal);
    virtual ~BrowserPane();

    virtual bool OnKeyEvent(InputEvent *event);
    virtual void OnCommand(int commandId);
    virtual void ScheduleTimer(int timerId, unsigned int delayMs);
    virtual void CancelTimer(int timerId);
    virtual void OnBrowserDialogClosed() { }
    virtual void OnBrowserDialogOpened() { }
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BrowserPane

## Summary

`BrowserPane` is a Browser-module `DialogPane`-derived base for browser command, key, and TimerHandler-facet behavior. It handles browser command codes, keyboard filtering, selection state, timer scheduling/cancellation through the inherited `+0xa4` timer/event facet, and inherited dialog activation.

Current confidence is high for browser-module ownership, the command/key/timer schedule/cancel methods, alert-string usage, vtable placement, source parent placement under [UID:0000HV][Browser](by-file/Browser.md), and the ordinary destructor route. B002's Rule 26 split pass moved the former mixed [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md) aggregate into exact children, so BrowserPane now owns the raw constructor-shaped body, ordinary non-deleting destructor, key event, and command dispatch children directly. B002's 2026-06-23 implementation resolves [UID:000408][0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor](by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md) as source-ready empty `BrowserPane::~BrowserPane()` C++ with compiler EH unwind refs from BrowserDialog, WebBoardDialog, and WebBoardDialogOld constructors. B001's 2026-07-26 UID000217 callback finalizes the timer pair as exact [UID:0004Y0][0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer](by-memory/0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer.md) and [UID:000217][0x004710d0-0x004710df.BrowserPaneCancelTimer](by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md) children using qualified inherited `TimerHandler` calls; `+0xa4` is now settled as Pane's inherited TimerHandler facet, not a BrowserPane field. Confidence remains capped below final-reconstruction quality because the constructor-shaped block at `0x0046a860` is still not an IDA-modeled function or referenced call target, the two cleaned constructor stack parameters are unused/unnamed, `OnKeyEvent` still needs accepted event field names, and several control-list helpers used by BrowserPane are shared `DialogPane` infrastructure rather than Browser-private methods.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp`
- Confidence: strong for browser subsystem ownership. A later `browser/BrowserPane.cpp` or `browser/BrowserDialog.cpp` split remains possible, but no current evidence requires it.

## Methods

- [UID:000407][0x0046a860-0x0046a898.BrowserPaneRawConstructor](by-memory/0x0046a860-0x0046a898.BrowserPaneRawConstructor.md) - constructor-shaped raw block; initializes the `DialogPane` base and installs the three BrowserPane vtable views. B012 byte accounting corrects the source-bearing half-open body to `0x0046a860-0x0046a89b`, with `ret 8` at `0x0046a898-0x0046a89b` and padding `0x0046a89b-0x0046a8a0`; the current child filename still carries the older endpoint for registry stability. IDA currently has no function at this start and the two cleaned but unread stack parameters keep constructor C++ blank.
- [UID:000408][0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor](by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md) - ordinary source-level `BrowserPane::~BrowserPane()` non-deleting destructor; emits an empty destructor body while vtable restoration, DialogPane base cleanup, and constructor-unwind funclets remain compiler output.
- [UID:00040A][0x0046a8e0-0x0046a901.BrowserPaneOnKeyEvent](by-memory/0x0046a8e0-0x0046a901.BrowserPaneOnKeyEvent.md) - key-event virtual; consumes the documented Back/modifier pattern and delegates to DialogPane/base input otherwise; blank C++ until accepted key-event fields exist.
- [UID:00040B][0x0046a910-0x0046aa34.BrowserPaneOnCommand](by-memory/0x0046a910-0x0046aa34.BrowserPaneOnCommand.md) - command virtual; handles `BCdp`, `BCfl`, `BCto`, and `0x572`, using direct alert strings at [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md), the shared OK string, `AlertPane`, and shared DialogPane activation.
- `0x0046ad80-0x0046aea8` is not a direct BrowserPane method. B012 confirms it is [UID:000017][BrowserDialog](by-class/BrowserDialog.md)-owned `BrowserDialog::OnInputEventWithBrowserReposition(...)`, installed in BrowserDialog vtable slot `0x00613414`; BrowserPane is only the inherited base dependency.
- [UID:00033C][0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor](by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md) - compiler scalar deleting destructor coverage routed after the ordinary destructor at source-order position `20`.
- [UID:0004Y0][0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer](by-memory/0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer.md) - exact `void ScheduleTimer(int timerId, unsigned int delayMs)` adapter; qualified source calls inherited `TimerHandler::ScheduleTimer(timerId, delayMs, 0, 0)`; class-child position `40`.
- [UID:000217][0x004710d0-0x004710df.BrowserPaneCancelTimer](by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md) - exact `void CancelTimer(int timerId)` adapter; qualified source calls inherited `TimerHandler::CancelTimer(timerId)`; class-child position `50`. `BrowserPanePlaySound` is rejected historical wording only.

## Shared Dialog-Control Helpers Used By BrowserPane

- [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) records the shared `DialogPane` control lookup, selection, pending-control update, and activation helpers around `0x0049dd20-0x0049dfc4`.
- Treat the Browser call sites as consumers of that helper inventory, not as proof that those helper bodies are BrowserPane-private methods.

## Live IDA Evidence

- IDA MCP reports no function at `0x0046a860`. The previous function is `sub_46A630` at `0x0046a630-0x0046a6ea`, and the next modeled function is `sub_46A8A0` at `0x0046a8a0-0x0046a8bf`.
- Raw disassembly for `0x0046a860-0x0046a89b` calls `sub_49D8A0` with `word_60DB20`, pushes `1`, `-1`, and `0x0060db20` before the base-constructor call, stores BrowserPane vtable views at `this+0x00 -> 0x006132ec`, `this+0xa0 -> 0x00613360`, and `this+0xa4 -> 0x00613390`, returns with `ret 8` at `0x0046a898-0x0046a89b`, and leaves five bytes of `0xcc` padding at `0x0046a89b-0x0046a8a0`. B012 local PE scans found no absolute pointer hit, RVA hit, rel32 call/jump, or pointer into the body for `0x0046a860`; this rejects a no-argument constructor draft and keeps the exact source signature unsafe.
- `sub_46A8A0` at `0x0046a8a0-0x0046a8bf` is [UID:000408][0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor](by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md). MCP session `80de0a67` reports the exact body as BrowserPane vtable restores at `this+0x00 -> 0x006132ec`, `this+0xa0 -> 0x00613360`, and `this+0xa4 -> 0x00613390`, followed by a tail jump to polluted-IDA DialogPane cleanup at `0x0049d9f0`. `get_bytes` confirms the body bytes through the final jump and one `0xcc` padding byte at `0x0046a8bf`.
- `xrefs_to 0x0046a8a0` reports exactly three refs: `0x005fac2e`, `0x005fad79`, and `0x005fae35`. B002 classifies them as C++ EH unwind funclet jumps from BrowserDialog, WebBoardDialog, and WebBoardDialogOld constructor FuncInfo chains, with unwind-map data refs at `0x0065976c`, `0x006593bc`, and `0x006596ec`; they are not ordinary source callsites or standalone-helper evidence.
- `sub_46A8E0` at `0x0046a8e0-0x0046a901` consumes the key event when `a2[4] == 8` and `a2[8] == 0x90`; otherwise it delegates to `sub_49E6E0(this, a2)`. Vtable data refs place it at `0x00613368`, `0x00613418`, and `0x00613708`.
- `sub_46A910` at `0x0046a910-0x0046aa34` handles commands `1111712880` (`BCdp`), `1111713388` (`BCfl`), `1111716975` (`BCto`), and `1394`; each handled case allocates `624` bytes via `sub_4F4AA0`, calls `sub_49FEB0` with a direct alert string and the shared `OK` text at `0x00613a18`, then closes through `sub_49DF20(this)`.
- Direct alert string refs from `sub_46A910` are `0x0046a97e -> 0x00613a20` (`Dispose`), `0x0046a9d5 -> 0x00613a30` (`Navigation Failed`), `0x0046aa06 -> 0x00613a54` (`Navigation Timeout`), and `0x0046a9ab -> 0x00613a7c` (`Web Board Request Timeout`).
- BrowserPane vtable slots confirm `OnCommand` at `0x00613348`, `0x006133f8`, `0x00613638`, and `0x006136e8`; timer scheduling at `0x0061334c`, `0x006133fc`, `0x0061363c`, and `0x006136ec`; and timer cancellation at `0x00613350`, `0x00613400`, `0x00613640`, and `0x006136f0`.
- `sub_470FC0` at exact `[0x00470fc0,0x00470fdc)` delegates timer scheduling through [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) as `this+0xa4, timerId, delayMs, 0, 0`; [UID:0004Y0][0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer](by-memory/0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer.md) now carries the formal source body.
- `sub_4710D0` at exact `[0x004710d0,0x004710df)` delegates cancellation through [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md) as `this+0xa4, timerId`; [UID:000217][0x004710d0-0x004710df.BrowserPaneCancelTimer](by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md) now carries the formal source body. It contains no audio or SoundManager logic.
- `sub_470690` at `0x00470690-0x004706e5` is the scalar deleting destructor slot at `0x006132ec`; it restores all three BrowserPane vtable views, calls `sub_49D9F0`, and conditionally frees through `sub_4F4AC0` when the delete flag permits.
- The complete BrowserPane object ends at `0x26c`: [UID:00003T][DialogPane](by-class/DialogPane.md) is exactly `0x26c` bytes and both WebBoardDialog families place their first derived `BrowserControlPane *` member at derived offset `+0x26c`. BrowserPane therefore contributes no new instance storage; derived browser-control storage belongs to WebBoardDialog/WebBoardDialogOld and must not be declared in BrowserPane.
- The primary BrowserPane, WebBoardDialog, and WebBoardDialogOld vtables carry the same two adjacent lifecycle-hook cells: `0x00613354`, `0x00613644`, and `0x006136f4` at primary slot `+0x68`, followed by `0x00613358`, `0x00613648`, and `0x006136f8` at primary slot `+0x6c`. Each cell is one four-byte pointer item with bytes `a0 b6 41 00`, a blank item name, no declared item type, blank regular/repeatable comments, and no inbound xrefs to the cell itself.
- All six cells resolve to the one-byte `ret` body at `0x0041b6a0`, currently named `@_guard_check_icall_nop@4` and typed `void()`. That address has `682` references because the linker folded many empty virtual bodies together; the generated label is not source identity. Only the `+0x68` cell is called by the three BrowserDialog-family close sequences, so the accepted human source identity is `virtual void OnBrowserDialogClosed() { }`. No Browser-family consumer reaches the adjacent `+0x6c` cell; slot adjacency and the lifecycle pair support the inferred companion `virtual void OnBrowserDialogOpened() { }`, with lower confidence than the called close hook but sufficient for the current first-draft header.
- [UID:0000HV][Browser](by-file/Browser.md) is scored `86/88`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/browser/"`, and groups BrowserPane with the dense browser/OLE module after IDA-backed boundary, helper, and global ownership checks.
- B009's 2026-06-27 live MCP recheck resolves [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md) / [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md) as an accepted source-facing `BrowserPane *` active owner/callback pointer. BrowserDialog, WebBoardDialog, and WebBoardDialogOld construction paths pass BrowserPane-derived `this` pointers into `BrowserControlPane::BrowserControlPane` after BrowserPane vtable setup, and BrowserControlPane dispatch/accelerator paths use the pointer for close/new-window/document-complete callbacks. This strengthens the BrowserPane callback/global relationship without changing the remaining class-level constructor, key-event-field, or source-split blockers.
- [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) is scored `90/91`, non-reconstructable/non-emitting, and records a shared `DialogPane` control-helper inventory. Exact child method bodies are class-owned by [UID:00003T][DialogPane](by-class/DialogPane.md) under the [UID:0000IT][DialogPane](by-file/DialogPane.md) file route; broad Browser call sites remain consumer evidence rather than Browser ownership.
- B002's 2026-06-20 split implementation confirms `sub_49DF20` should be referenced as shared DialogPane activation, not Browser-private `ActivateItem`; command-handler C++ should use named browser command constants and the [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md) alert constants rather than decimal ids or generated pointer-global aliases.

## Batch 106 Parent-Gate Refresh

2026-06-08 read-only IDA MCP `py_eval` reconfirmed the BrowserPane method evidence used by this class page:

| Range | Current IDA function | Vtable refs / notes |
| --- | --- | --- |
| `0x0046a860` | no modeled IDA function | Still a raw constructor-shaped block; this remains the main final-layout caveat. |
| `0x0046a8a0-0x0046a8bf` | `sub_46A8A0` | Ordinary non-deleting `BrowserPane::~BrowserPane()` body; EH/table xrefs are constructor-unwind actions, and [UID:00033C][0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor](by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md) remains separate compiler glue. |
| `0x0046a8e0-0x0046a901` | `sub_46A8E0` | Key-event virtual slot refs at `0x00613368`, `0x00613418`, and `0x00613708`. |
| `0x0046a910-0x0046aa34` | `sub_46A910` | Command virtual slot refs at `0x00613348`, `0x006133f8`, `0x00613638`, and `0x006136e8`. |
| `0x00470690-0x004706e5` | `sub_470690` | Scalar deleting destructor refs include BrowserPane primary vtable slot `0x006132ec`. |
| `0x00470fc0-0x00470fdc` | [UID:0004Y0][0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer](by-memory/0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer.md) | Timer schedule slot refs at `0x0061334c`, `0x006133fc`, `0x0061363c`, and `0x006136ec`; exact inherited-base CPP at position `40`. |
| `0x004710d0-0x004710df` | [UID:000217][0x004710d0-0x004710df.BrowserPaneCancelTimer](by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md) | Timer cancel slot refs at `0x00613350`, `0x00613400`, `0x00613640`, and `0x006136f0`; exact inherited-base CPP at position `50`; stale `PlaySound` rejected. |

[UID:0000HV][Browser](by-file/Browser.md) is now scored `86/88`, so the direct parent side clears the corrected `85/85` gate. This class now clears `85/86`; retaining `AUTOGEN_PARENT_UID:0000HV` is justified for class-level routing, while exact constructor/source split questions continue to block final C++.

## BrowserPane Timer Surface Closure - 2026-07-26

### Inheritance And Source Model

- BrowserPane derives through DialogPane and Pane. Pane contributes EventHandler and TimerHandler facets at complete-object offsets `+0xa0` and `+0xa4`.
- BrowserPane constructor/destructor families store primary, EventHandler, and TimerHandler vtable views at `+0`, `+0xa0`, and `+0xa4`. DialogPane is size `0x26c`, and BrowserDialog's first owned pointer starts at `+0x26c`; BrowserPane adds no timer member at `+0xa4`.
- `m_timerHandler`, a second direct TimerHandler base, explicit vptr members, and raw pointer arithmetic are rejected source shapes. The exact source uses qualified inherited-base calls so the compiler regenerates the receiver adjustments.
- The source names are finalized as `ScheduleTimer`, `CancelTimer`, `timerId`, and `delayMs`, consistent with the accepted TimerHandler API. `ScheduleTimerEvent`, `CancelTimerEvent`, and `BrowserPanePlaySound` are historical candidates only.

### Exact Slot Matrix

| Primary table | Schedule slot `+0x60` | Cancel slot `+0x64` | Interpretation |
| --- | --- | --- | --- |
| BrowserPane | `0x0061334c -> 0x00470fc0` | `0x00613350 -> 0x004710d0` | authored BrowserPane pair |
| BrowserDialog | `0x006133fc -> 0x00470fc0` | `0x00613400 -> 0x004710d0` | inherited unchanged |
| WebBoardDialog | `0x0061363c -> 0x00470fc0` | `0x00613640 -> 0x004710d0` | inherited unchanged |
| WebBoardDialogOld | `0x006136ec -> 0x00470fc0` | `0x006136f0 -> 0x004710d0` | inherited unchanged |

The pair has no ordinary code callers because both methods are reached through primary vtables. Derived-table reuse is inheritance evidence and does not transfer source ownership to BrowserDialog or WebBoard sources.

### Deterministic Source-Child Route

| Position | Child | Source disposition |
| ---: | --- | --- |
| `10` | [UID:000408][0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor](by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md) | exact empty ordinary destructor body |
| `20` | [UID:00033C][0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor](by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md) | compiler ABI coverage comment to UID000408 |
| `30` | [UID:00040B][0x0046a910-0x0046aa34.BrowserPaneOnCommand](by-memory/0x0046a910-0x0046aa34.BrowserPaneOnCommand.md) | source-authored command method |
| `40` | [UID:0004Y0][0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer](by-memory/0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer.md) | exact qualified TimerHandler schedule call |
| `50` | [UID:000217][0x004710d0-0x004710df.BrowserPaneCancelTimer](by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md) | exact qualified TimerHandler cancel call |

All five source fragments route through this class to [UID:0000HV][Browser](by-file/Browser.md). The class CPP block is `[[CHILDREN]]`, while the formal H block now carries the complete no-new-data BrowserPane declaration used by those children: constructor compatibility, ordinary destructor, key/command/timer virtuals, and the two empty lifecycle hooks. Exact method bodies remain on their by-memory pages; the unresolved raw constructor body and inferred event-field spellings do not justify suppressing the evidence-consistent class declaration.

### Boundary, Ownership, And Negative Evidence

- UID0004Y0 is exact `[0x00470fc0,0x00470fdc)` with seven preceding `0xcc` bytes and successor `sub_470FDC` at its end. Mixed UID00033M remains a one-child non-emitting index for the surrounding COM-thunk run.
- UID000217 is exact `[0x004710d0,0x004710df)` between four and one `0xcc` padding bytes; UID000216 and UID000218 remain separate protected neighbors.
- TimerHandler owns the generic callees at `0x005975e0` and `0x00597610`, while BrowserPane owns these two primary-vtable adapters. SoundManager has no local operation or ownership evidence.
- The accepted current source root is Browser.cpp. Historical BrowserPane.cpp splitting remains possible but does not alter class ownership, exact behavior, or the current emitter chain.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | The class page documents exact BrowserPane children for the raw constructor, ordinary non-deleting destructor, key event, command dispatch, scalar-wrapper coverage, and exact ScheduleTimer/CancelTimer methods; complete inherited TimerHandler-facet semantics, source-child ordering, vtable matrix, boundaries, Browser route, browser alert strings, shared DialogPane helper boundary, stale-name corrections, no-aggregate split policy, exact `0x26c` no-new-data boundary, and the complete first-draft CPP/H route are preserved. |
| Confidence | 94 | BrowserPane ownership, Browser routing, exact timer pair, inherited Pane facet, four-family slot reuse, BrowserDialog-owned boundary, destructor classification, exact no-new-data size, three-family lifecycle-hook cells, the called close hook, and the adjacent inferred open hook are supported by live MCP session `5a570ede`, current Pane/PaneVtables/TimerHandler docs, B012 local PE facts, exact split children, and B002 EH unwind-map evidence. Confidence remains below final audit because the raw constructor entry/body, original constructor parameter spellings, OnKeyEvent field spellings, and historical source-file split remain inferred rather than recovered symbols. |
| Parent | [UID:0000HV][Browser](by-file/Browser.md) | Child `85/86` and parent `86/88` clear the strict gate; Browser is the direct source root for this class cluster, while exact one-file versus split-file layout remains a source organization caveat. |

## Open Questions

- Review the `0x0046a860` projected constructor boundary before assigning final constructor names, source lines, or a declaration/body.
- Finalize whether the original source used a standalone `BrowserPane.cpp` or kept BrowserPane in the broader `Browser.cpp` module; current emission remains Browser.cpp and this does not block the exact timer children.
- If the registry can safely tolerate a path rename, consider renaming the current [UID:000407][0x0046a860-0x0046a898.BrowserPaneRawConstructor](by-memory/0x0046a860-0x0046a898.BrowserPaneRawConstructor.md) file to the B012-corrected `0x0046a860-0x0046a89b` endpoint; this pass documents the corrected endpoint without renaming the file.

## Historical/Stale Assumptions Corrected

- Older BrowserPane split text treated `0x0046a898` as the constructor body end or mentioned a generated source-map lead near `0x0046a89a`. B012 byte accounting shows `ret 8` occupies `0x0046a898-0x0046a89b`; only `0x0046a89b-0x0046a8a0` is padding.
- `BrowserPanePlaySound` is stale generated/historical wording. `0x004710d0-0x004710df` adjusts to `this+0xa4` and tail-jumps to the generic `TimerHandler::CancelTimer` wrapper at `0x00597610`; it is a timer-cancel forwarder, not sound playback.
- Earlier `ScheduleTimerEvent` / `CancelTimerEvent` and field-delegation wording is superseded by exact UID0004Y0/UID000217 source children and the inherited Pane TimerHandler-facet model. No BrowserPane timer field exists.
- `0x0046ad80-0x0046aea8` is BrowserDialog-owned despite BrowserPane inheritance.
- Generated `g_pBrowserFileLoadText` and `g_pBrowserTimeoutText` names are aliases over direct Browser alert string literals, not separate pointer-global storage.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000017][BrowserDialog](by-class/BrowserDialog.md), [UID:00003T][DialogPane](by-class/DialogPane.md)
- Globals: [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md), [UID:0000QC][g_pBrowserFileLoadText](by-global/g_pBrowserFileLoadText.md), [UID:0000QF][g_pBrowserTimeoutText](by-global/g_pBrowserTimeoutText.md)
- Memory: [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md), [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md), [UID:0004Y0][0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer](by-memory/0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer.md), [UID:000217][0x004710d0-0x004710df.BrowserPaneCancelTimer](by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md), [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md), [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md)

## Changes

- 2026-08-03 B002 UID000212 implementation callback:
  - Raised `89/93 -> 90/94`, set class CPP to `[[CHILDREN]]`, and added the complete no-new-data BrowserPane formal H declaration for `NexusTK/browser/Browser.h`.
  - Proved the `0x26c` class boundary from DialogPane size and the first derived WebBoardDialog-family member, rejecting browser-control storage in BrowserPane.
  - Added the three-family primary `+0x68/+0x6c` lifecycle-hook cell matrix, the 682-reference folded one-byte body, the called `OnBrowserDialogClosed` identity, and the inferred adjacent `OnBrowserDialogOpened` companion while preserving the raw-constructor, event-field, and historical source-split caveats.

- 2026-07-26 B001 UID000217 timer-surface implementation callback:
  - Raised `88/90 -> 89/93`, preserving Browser file ownership/emission and blank broad class formals.
  - Added exact UID0004Y0 ScheduleTimer and renamed UID000217 CancelTimer children, final names/signatures, inherited Pane TimerHandler facet at `+0xa4`, complete four-family `+0x60/+0x64` slot matrix, exact boundary/split evidence, and deterministic child positions `10/20/30/40/50`.
  - Historical PlaySound/Event suffix/member-delegation alternatives remain as rejected evidence. TimerHandler owns only the generic callees, derived BrowserDialog/WebBoard tables inherit the pair, and Browser.cpp remains the accepted current source root.

- Before: the main memory reference pointed at `0x0046a860-0x0046ad09.BrowserPaneAndDialog`.
- Changed to: the reference now points at `0x0046a860-0x0046ad0a.BrowserPaneAndDialog`, and the related `0x0046ad10-0x0046b51d` resized-input/draw/helper cluster is linked separately.
- Summary/evidence: IDA MCP corrected the BrowserDialog constructor endpoint to `0x0046ad0a` and shows `0x0046ad80` installed through the BrowserDialog/BrowserPane vtable region.

- What existed before: the page documented BrowserPane behavior and range corrections, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `70/76`.
- Summary and evidence: command handling, keyboard behavior, alert strings, timer delegation, and helper references were covered; later B012 evidence refines the timer tail helper from stale sound wording to timer cancellation. The projected constructor and possible shared helper ownership limited confidence.
- 2026-06-03 parent attachment and shared-helper correction:
  - What existed before: the page was reconstructable in substance but had blank autogen metadata, still listed shared selection helpers as BrowserPane methods, and kept `70/76` scoring.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:80`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000HV][Browser](by-file/Browser.md); the `0x0049dd20-0x0049dfc4` helpers are now explicitly treated as shared [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) consumers rather than Browser-private bodies.
  - Summary/evidence: Browser parent placement is supported by the `84/88` Browser file doc, command/key/sound methods and alert strings remain Browser-specific, while the shared-helper page records broad dialog/control caller evidence. C++ remains blank because the projected constructor boundary and final source split are below the 95+ reconstruction gate.
- 2026-06-04 live IDA refresh:
  - What existed before: BrowserPane was scored `74/80` and still depended on stale constructor phrasing while omitting several exact vtable slots and method-body facts.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, with the C++ reconstruction intentionally left blank.
  - Summary/evidence: live IDA confirmed the raw constructor-shaped block then documented under `0x0046a860-0x0046a898`, the three BrowserPane vtable writes at `0x006132ec`, `0x00613360`, and `0x00613390`, method ranges for `sub_46A8A0`, `sub_46A8E0`, `sub_46A910`, `sub_470690`, `sub_470FC0`, and `sub_4710D0`, command-to-alert-string refs, and vtable slots for command/timer dispatch. Later B012 byte accounting corrects the constructor body through `0x0046a89b` and the `sub_4710D0` role to timer cancellation. The score remained capped because `0x0046a860` was still not an IDA-modeled function or referenced call target, helper ownership remained partly shared with `DialogPane`, and the original source split was not proven to the final reconstruction bar.
- 2026-06-08 A007 Batch 106 parent-gate refresh:
  - Changed score from `82/84` to `85/86`.
  - Retained `AUTOGEN_PARENT_UID:0000HV` because [UID:0000HV][Browser](by-file/Browser.md) is now `86/88`, and this class now clears the corrected `85/85` gate.
  - Evidence: read-only IDA MCP reconfirmed the modeled BrowserPane key, command, destructor, timer, and then-still-stale sound-named helper vtable refs; the unresolved `0x0046a860` raw constructor-shaped block remained documented as the completion/confidence cap rather than a routing blocker for [UID:000217][0x004710d0-0x004710df.BrowserPaneCancelTimer](by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md). B012 later corrected [UID:000217][0x004710d0-0x004710df.BrowserPaneCancelTimer](by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md) to timer cancellation.
- 2026-06-20 B002 Rule 26 split implementation:
  - Before: `85/86`, with BrowserPane evidence still folded into mixed [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md).
  - After: `87/88`, with exact children [UID:000407][0x0046a860-0x0046a898.BrowserPaneRawConstructor](by-memory/0x0046a860-0x0046a898.BrowserPaneRawConstructor.md), [UID:000408][0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor](by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md), [UID:00040A][0x0046a8e0-0x0046a901.BrowserPaneOnKeyEvent](by-memory/0x0046a8e0-0x0046a901.BrowserPaneOnKeyEvent.md), and [UID:00040B][0x0046a910-0x0046aa34.BrowserPaneOnCommand](by-memory/0x0046a910-0x0046aa34.BrowserPaneOnCommand.md) linked and the former aggregate converted to a non-emitting split index.
  - Summary/evidence: incorporated B002's BrowserPane ownership decisions, raw constructor `ret 8`/no-ref caveat, then-open destructor classification gate, key-event field-name gate, command FourCC meanings, Browser alert constants, shared OK string, AlertPane constructor use, DialogPane activation helper ownership, rejected generated names, and first-draft `OnCommand` C++ routing.
- 2026-06-21 B012 BrowserPane class source-quality incorporation:
  - Before: `87/88`, with lingering timer/sound wording, stale direct-method wording for `0x0046ad80`, and constructor endpoint prose inherited from the older split.
  - After: `87/89`, keeping owner [UID:0000HV][Browser](by-file/Browser.md), reconstructable true, emitter [UID:0000HV][Browser](by-file/Browser.md), and blank class-level C++.
  - Summary/evidence: incorporated B012's local PE reanalysis: raw constructor source-bearing range `0x0046a860-0x0046a89b`, `ret 8` at `0x0046a898-0x0046a89b`, padding `0x0046a89b-0x0046a8a0`, no absolute/RVA/rel32 entry or pointer-into-body evidence, schedule/cancel TimerHandler facet pairing, stale `BrowserPanePlaySound` rejection, BrowserDialog ownership for `0x0046ad80`, shared DialogPane helper exclusions, and Browser.cpp source-root decision. Formal class C++ remains blank because class pages should not host method bodies and the constructor signature/timer-facet declaration are still not source-quality.
- 2026-06-23 B002 BrowserPane destructor source-quality implementation:
  - Before: `87/89`, with [UID:000408][0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor](by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md) still named `0x0046a8a0-0x0046a8bf.BrowserPaneCleanupWrapper` and pending EH/destructor classification with blank C++.
  - After: `88/90`, with [UID:000408][0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor](by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md) classified as ordinary source-level `BrowserPane::~BrowserPane()` and emitting an empty destructor body through [UID:0000HV][Browser](by-file/Browser.md).
  - Summary/evidence: MCP session `80de0a67` confirms `sub_46A8A0` exact bytes/range/padding, BrowserPane vtable restores, tail jump to polluted-IDA DialogPane cleanup at `0x0049d9f0`, constructor-unwind refs at `0x005fac2e`, `0x005fad79`, and `0x005fae35`, unwind-map data refs at `0x0065976c`, `0x006593bc`, and `0x006596ec`, and separate scalar deleting destructor wrapper [UID:00033C][0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor](by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md).
- 2026-06-25 B002 DialogControlPaneHelpers synchronization:
  - Refreshed the shared-helper references for [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) from stale `74/84` file-attached wording to current `90/91`, non-reconstructable/non-emitting inventory wording. Exact helper children remain [UID:00003T][DialogPane](by-class/DialogPane.md)-owned, and BrowserPane remains a consumer rather than an owner of those helper bodies.
- 2026-06-27 B009 g_activeBrowserPane source-quality sync:
  - Score unchanged at `88/90`.
  - Summary/evidence: updated the global relationship from high-probability owner/callback wording to accepted `BrowserPane *` source-facing storage. B009 live MCP shows BrowserPane-derived dialog constructors publish `this` into [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md), while BrowserControlPane dispatch/accelerator consumers use it as the active BrowserPane close/callback target. The class page still keeps constructor signature, key-event fields, and source split caveats outside this global-storage fix.
