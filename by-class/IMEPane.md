*** UID:00006H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "IMEPanes.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/core/Pane.h"
#include "../util/List.h"

class Event;
class IMECandidatePane;
class IMECompositionPane;
class IMEStatusPane;

class IMEPane : public Pane
{
    friend class IMECandidatePane;
    friend class IMECompositionPane;

public:
    IMEPane();
    virtual ~IMEPane();

    void SetFocusPane(Pane *pane, bool focused);
    bool IsIMESupported(const Event *event);
    bool HandleIMEMessage(const Event *event);

private:
    void UpdateFocusCaretAnchor();

    IMEStatusPane *statusPane;
    Pane *activeChildPane;
    IMECandidatePane *candidatePane;
    List focusPaneList;
    int focusCaretAnchorY;
    int focusCaretAnchorX;
};

extern IMEPane *g_pIMEPane;

typedef char IMEPaneSizeMustBe288[
    sizeof(IMEPane) == 0x120 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# IMEPane

## Status

- Likely source file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Address range: [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md), with destructor wrappers in [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- Current recovered file: `source-3/simroot_v2/class_IMEPane.cpp`
- Confidence: very strong for class ownership, complete field/member order, lifecycle, source order, focus-list pointer-slot semantics, and the retained private anchor-refresh method; exact original private/helper spellings remain descriptive.

## Class Purpose

`IMEPane` is the process-level pane-side IME coordinator. It stores [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md), tracks focused text-entry pane pointers in an embedded `List`, refreshes cached composition/candidate anchors from the last focused pane, creates and destroys composition/candidate child panes in response to IME events, and provides `SetFocusPane` for text controls.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `IMEPane` | [UID:0004CA][0x004e7f20-0x004e7ff5.IMEPaneConstructor](by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md) | `88/91`; formal C++ populated. Constructs the root IME pane as `IMEPane::IMEPane() : Pane(4), focusPaneList(4, 4)`, publishes `g_pIMEPane`, zeroes `statusPane +0xf8`, `activeChildPane +0xfc`, `candidatePane +0x100`, zeroes `focusCaretAnchorY/X`, calls `SetPaneOrder(NULL, NULL)`, and treats vtable/EH/raw helper stores as compiler lowering rather than source. |
| `~IMEPane` | [UID:0004CB][0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor](by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md) | `91/94`; formal C++ populated. Sole human destructor releases `statusPane +0xf8`, `activeChildPane +0xfc`, and `candidatePane +0x100` through `Pane::MarkForDeletion`, relies on owned `focusPaneList +0x104` cleanup, clears `g_pIMEPane`, and leaves the exact UID00031K hidden-flag/release/no-op wrapper entirely compiler-owned. |
| `SetFocusPane` | [UID:0004CC][0x004e80a0-0x004e810b.IMEPaneSetFocusPane](by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md) | `89/91`; formal C++ populated. Modeled `0x6b` body obtains a local count through `focusPaneList.GetCount()`, scans the embedded list backward, removes an existing matching `Pane *` through `List::RemoveAt`, and conditionally appends the pane through `List::Append` when `focused` is true. |
| `UpdateFocusCaretAnchor` | [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) | `91/93`; retained private source method at exact `[0x004e8110,0x004e8192)`. It dereferences the last `TextEditPane *` pointer slot from `focusPaneList`, obtains two short caret values plus caret-local and pane-screen Points, writes X `+0x11c` then Y `+0x118`, or clears both when signed count is nonpositive. UID00018A calls it at source level; the shipped compiler inlined that call while retaining this out-of-line body. No null/bounds/sentinel/failure checks or compiler mechanics are authored. |
| `IsIMESupported` | [UID:0004CD][0x004e81a0-0x004e81a5.IMEPaneIsIMESupported](by-memory/0x004e81a0-0x004e81a5.IMEPaneIsIMESupported.md) | `90/92`; formal C++ populated. Secondary `EventHandler` table method at table `0x0061c548`, slot `+0x08`, vtable cell `0x0061c550`; exact bytes `b0 01 c2 04 00` (`mov al, 1; retn 4`) always return true. The unused `const Event *event` argument is ABI-required by the `retn 4` slot shape, so the stale no-argument `IsIMESupported() const` declaration is rejected. |
| `HandleIMEMessage` | [UID:0004CE][0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage](by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md) | `89/91`; formal C++ populated. Root IME event dispatcher reached through the secondary vtable at complete-object `+0xa0`; handles event types `12`, `14`, `15`, and `16`, returns false for type `13`/default, maps adjusted `this+0x5c` to complete `activeChildPane +0xfc`, maps adjusted `this+0x60` to complete `candidatePane +0x100`, and dispatches candidate-list messages to `IMECandidatePane::HandleIMEMessage`. |
| `ClearIMEPaneSingleton` | [UID:00031H][0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper](by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md) | Tiny file-local helper that clears [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md). |
| `ScalarDeletingDestructor` | [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md) | `92/94`; exact class-owned compiler wrapper, false/non-emitting with blank formal CPP/H. Primary and `this-0xa0`/`this-0xa4` vtable routes repeat UID0004CB cleanup and add only hidden deleting-flag allocation selection. |

## Observed State

```text
IMEPane
  +0x0f8  statusPane / status child slot deleted by root teardown; UID0004CE does not create/delete it
  +0x0fc  activeChildPane / activePopupPane
  +0x100  candidatePane
  +0x104  focusPaneList / embedded List of TextEditPane* element slots
  +0x110  focusPaneList.m_count / embedded List member state, not a separate IMEPane field
  +0x118  focusCaretAnchorY
  +0x11c  focusCaretAnchorX
```

The X/Y ordering is now resolved by [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) and [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md): `+0x11c` participates in horizontal popup width/screen-width math, while `+0x118` participates in top/bottom line-height/screen-height math. B001's [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) pass identifies `+0xfc` as the active child/popup pane pointer used to place the candidate list above the active child when the popup would exceed the screen bottom.

[UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) resolves the class's private anchor-refresh operation and source order. The method follows `SetFocusPane`, is separated from it by five `0xcc` bytes, and precedes `IsIMESupported` by fourteen `0xcc` bytes. It obtains a local count through `focusPaneList.GetCount()`, whose inline read observes `focusPaneList.m_count` at complete-object `+0x110`, asks List virtual slot `+0x10` for the final element-storage address, dereferences the stored text-entry pointer, and uses current `Point { y, x }` ordering. The absence of a modeled function/direct xref is retained as reachability evidence, not as a no-code disposition.

[UID:0004CE][0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage](by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md) resolves the root IME handler's adjusted-this model. The handler is entered through the secondary vtable stored at complete-object `+0xa0`; its adjusted `this+0x5c` stores/deletes complete `+0xfc activeChildPane`, and its adjusted `this+0x60` stores/deletes complete `+0x100 candidatePane`. The adjacent `+0xf8 statusPane` slot is supported by constructor/destructor evidence but is not a UID0004CE status branch.

[UID:0004CB][0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor](by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md) resolves the root ordinary destructor as the sole emitting `IMEPane::~IMEPane()` body. MCP confirms exact range `0x004e8000-0x004e8098`, `0x98` bytes, child release calls for `statusPane`, `activeChildPane`, and `candidatePane` through `Pane::MarkForDeletion`, owned `focusPaneList +0x104` cleanup through `List::~List()`, singleton clear at `0x004e8079`, and compiler/base Pane teardown. The formal source does not clear the child slots, handwrite `focusPaneList.~List()`, or include raw helper names, vtable stores, base teardown, or scalar-delete wrapper logic. UID00031K is exact 217-byte class-owned compiler output with blank formals; its primary/two-adjustor routes repeat this cleanup and add only hidden flag allocation selection. Complete-object `+0x110` is `focusPaneList.m_count`, not a separate field.

## Evidence Notes

- IDA MCP confirms all listed function starts and sizes.
- 2026-07-02 B008 UID0004CA implementation callback resolves the root constructor as an emitting method. Current MCP proves exact `0x004e7f20-0x004e7ff5` range, `0xd5` size, `0xcc` padding before/after, sole startup caller at `0x004f639e`, `Pane(4)` base construction, `g_pIMEPane` publish at `0x004e7f68`, compiler-only IMEPane vtable stores, `focusPaneList +0x104` construction as `List(4,4)`, child-slot zeroing for `statusPane +0xf8`, `activeChildPane +0xfc`, and `candidatePane +0x100`, caret-anchor zeroing at `+0x118/+0x11c`, and `SetPaneOrder(NULL,NULL)` with no `AddToLayer`. `focusPaneCount +0x110` is the embedded `focusPaneList` count slot/source-facing alias initialized by `List(4,4)`, not a separate constructor write. No-code, direct-file, InputMan/Application/dependency ownership, raw helper/vtable/EH source, and separate `focusPaneCount = 0` alternatives are rejected.
- IDA xrefs to `0x004e80a0` include text-edit and self-save text input paths at `0x0058e0d9`, `0x0058e20c`, `0x0058ead9`, and `0x00595463`.
- 2026-07-02 B006 UID0004CC implementation callback resolves `SetFocusPane` as an emitting method. Current MCP confirms `sub_4E80A0` size `0x6b`, exact range `0x004e80a0-0x004e810b`, padding before and after, exactly four direct callers, no direct named callees outside embedded `List` virtual calls, and two explicit arguments. The declaration is now `void SetFocusPane(Pane *pane, bool focused);`: caller polarity passes `1` from TextEdit active/registration paths and `0` from TextEdit/TextBox teardown or inactive/unregistered paths. TextEditPane, TextBoxPane, InputMan, aggregate-only emission, no-code, and merge with [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) are rejected.
- IDA xrefs to `0x0069b458` show reads/writes across `IMEPane`, composition, candidate, text-edit, and startup/teardown paths.
- 2026-05-26 IDA MCP storage check confirms [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md) as a 4-byte `.data` singleton with 17 data references.
- 2026-06-08 A001 Batch131 historically described a separate `focusPaneCount` while splitting the raw focus/caret helper and scalar wrapper. Current source-shape reanalysis supersedes only that field interpretation: [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) reads inline `focusPaneList.m_count` at complete-object `+0x110`, and [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md) is now exact `92/94` class-owned compiler output reached through primary and two adjusted vtable routes, false/non-emitting with blank formals.
- 2026-06-17 B003 reanalysis of [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) correctly validates the same focus-list and anchor fields inline. Its historical conclusion that no direct machine call forbids a source method is superseded: the sequence at `0x004e74b0-0x004e751d` is the optimizer-inline expansion of the private source call.
- 2026-06-17 B001 reanalysis of [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) validates `g_pIMEPane+0xfc` as an active child/popup pane pointer: the candidate popup queries that pane's bounds through inherited virtual slot `+0x28` only when screen-bottom clamping needs an alternate vertical anchor.
- [UID:00031H][0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper](by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md) is file-local static cleanup support for this source family rather than an `IMEPane` method, but it is listed here because it clears this class's singleton.
- Direct child assignments are justified for [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) and [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md). UID00031G is now complete source-bearing method documentation at `91/93`; UID00031K remains the compiler wrapper distinction.
- Historical 2026-06-30 B008 callback: the formal root shell intentionally omitted `UpdateFocusCaretAnchor` because no function/xref route was known. Fresh B002 exact-range and optimizer-inline analysis supersedes only that no-code conclusion. The B008 friends, fields, singleton declaration, and all unrelated class evidence remain valid.
- 2026-07-15 B002 source-operation proof: exact target bytes/hash, two-branch CFG, stable padding, unique prologue signature, zero function/xref/raw-pointer/rel32 routes, exact List slot dereference, helper ABI, Point ordering, and UID00018A inline equivalence support one retained private method. No runtime direct-call claim is made.
- 2026-07-01 B010 UID0004CE implementation callback adds the accepted root IME-message dispatcher evidence: current MCP proves the `HandleIMEMessage` secondary vtable route through complete-object `+0xa0`, the adjusted `this+0x5c -> complete +0xfc activeChildPane` mapping, the adjusted `this+0x60 -> complete +0x100 candidatePane` mapping, event cases `12/14/15/16`, event type `13`/default false, and no status-pane branch in UID0004CE. The class shell now includes `candidatePane +0x100`; it also records `statusPane +0xf8` as constructor/destructor/status-slot evidence, not as UID0004CE behavior.
- 2026-07-01 B007 UID0004CD implementation callback repairs the `IsIMESupported` signature and method note: current MCP proves the exact `0x004e81a0-0x004e81a5` body, one IMEPane secondary-table data xref at `0x0061c550`, no code callers/callees, and the neighboring [UID:0004CE][0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage](by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md) slot at `0x0061c554`. The declaration is `bool IsIMESupported(const Event *event);` because `retn 4` consumes the EventHandler-slot argument; the stale no-argument `const` declaration and shared-helper/no-code alternatives are rejected.
- 2026-07-02 B011 UID0004CB implementation callback resolves the ordinary destructor as an emitting method. Current MCP proves `0x004e8000-0x004e8098` size `0x98`, `0xcc` padding at the end, child releases for `statusPane +0xf8`, `activeChildPane +0xfc`, and `candidatePane +0x100` through `Pane::MarkForDeletion`, owned `focusPaneList +0x104` cleanup through `List::~List()`, `g_pIMEPane` clear at `0x004e8079`, Pane base teardown as compiler/base cleanup, no direct xrefs as a scalar-wrapper reachability caveat rather than no-code proof, and no child-slot null stores.

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md)
- [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md)
- [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md)
- [UID:00031H][0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper](by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md)
- [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md)
- [UID:00006J][InputMan](by-class/InputMan.md)

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `91` | The complete class union includes the corrected CPP/H split, complete Pane/List dependencies, exact `0x120` human layout with one embedded `0x14` List, constructor/destructor/focus/event methods, retained private anchor method, singleton, source order, and exact non-emitting UID00031K distinction. |
| Confidence `94` | Ownership, layout arithmetic, source module, UID0004CB/UID00031K parity, embedded-count interpretation, and formal source shape agree. Only unavailable original private/helper spellings and out-of-line runtime reachability remain inferred. |

## Changes

- 2026-08-12 B006 UID00031K accepted implementation callback:
  - Raised class metadata from `90/92` to `91/94` after physically repairing its source form.
  - Moved all declarations, complete Pane/List dependencies, `extern g_pIMEPane`, and `0x120` size guard into formal H; formal CPP now contains only `#include "IMEPanes.h"` plus `[[CHILDREN]]`.
  - Removed emitted UID/address/offset reconstruction comments and the impossible overlapping `focusPaneCount` member. The one complete `List focusPaneList` owns `m_count` at complete-object `+0x110`; UID0004CC/UID00031G use `GetCount()` locals.
  - Recorded UID0004CB as the sole `91/94` human destructor and UID00031K as exact `92/94` class-owned compiler output with blank emitter/formals.
- 2026-07-15 B002 accepted UID00031G callback:
  - Before: `88/91`; complete class shell omitted the private helper and classified UID00031G as no-code.
  - Changed to: `90/92`; added only the accepted private declaration, clarified `focusPaneList` as pointer slots, and documented exact retained-method/source-order/inlining/no-check evidence.
  - Preserved: owner/emitter/position `0000K5/0000K5/0`, all fields/friends/methods/children, constructor/destructor/event evidence, and historical B008/B003 facts labeled superseded only where their no-code inference changed.
- 2026-07-02 B008 UID0004CA implementation callback:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:0004CA][0x004e7f20-0x004e7ff5.IMEPaneConstructor](by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md) now emits formal `IMEPane::IMEPane()` C++ through this class. Method and evidence notes record accepted `88/91`, exact `0xd5` range and `0xcc` padding, sole startup caller, `Pane(4)`, `g_pIMEPane = this`, compiler-only vtable stores, `focusPaneList(4,4)`, child pointer zeroing, caret-anchor zeroing, `SetPaneOrder(NULL,NULL)`, no `AddToLayer`, no raw helper/vtable/EH source, and `focusPaneCount +0x110` as the embedded list count alias rather than a separate constructor store.
- 2026-07-02 B011 UID0004CB implementation callback:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:0004CB][0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor](by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md) now emits formal `IMEPane::~IMEPane()` C++ through this class. Method, state, and evidence notes record accepted `88/91`, exact `0x98` boundary, `statusPane +0xf8`, `activeChildPane +0xfc`, `candidatePane +0x100`, child release through `Pane::MarkForDeletion`, owned `focusPaneList` cleanup, `focusPaneCount +0x110` as the embedded list count alias, singleton clear, scalar-wrapper separation, no child-slot null stores, and rejected raw-helper/base/vtable/scalar-delete/no-code alternatives.
- 2026-07-02 B006 UID0004CC implementation callback:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:0004CC][0x004e80a0-0x004e810b.IMEPaneSetFocusPane](by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md) now emits formal `IMEPane::SetFocusPane(Pane *pane, bool focused)` C++ through this class. The declaration was corrected from stale one-argument `void SetFocusPane(Pane *pane);` to the two-argument signature, and method/evidence notes record the exact `0x6b` modeled body, padding boundaries, four text-entry callers, caller-polarity `focused` flag, `List::GetElementAt`/`RemoveAt`/`Append` mapping over `focusPaneList +0x104` and `focusPaneCount +0x110`, and rejected no-code/alternate-owner/merge alternatives.
- 2026-07-01 B007 UID0004CD implementation callback:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:0004CD][0x004e81a0-0x004e81a5.IMEPaneIsIMESupported](by-memory/0x004e81a0-0x004e81a5.IMEPaneIsIMESupported.md) now emits formal `IMEPane::IsIMESupported(const Event * /*event*/)` C++ through this class. The class shell declaration was corrected from stale `bool IsIMESupported() const;` to `bool IsIMESupported(const Event *event);`; method/evidence notes record the secondary table `0x0061c548`, slot `+0x08`, vtable cell `0x0061c550`, exact always-true bytes, no direct callers/callees, adjacent UID0004CE slot, ABI-required unused Event pointer, and rejected no-argument/shared-helper/no-code/direct-file/EventHandler-owner alternatives.
- 2026-07-01 B010 UID0004CE implementation callback:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:0004CE][0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage](by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md) now emits formal `IMEPane::HandleIMEMessage(const Event *event)` C++ through this class. The formal shell and observed state now preserve `activeChildPane +0xfc`, add `candidatePane +0x100`, and document adjacent `statusPane +0xf8` as constructor/destructor/status-slot evidence only. Method/evidence notes record the secondary adjusted-this model, composition/candidate event cases, candidate dispatch, source-level switch, and the rejected status-branch/direct-file/aggregate-only/no-code alternatives.
- 2026-06-30 B008 implementation callback:
  - Before: score was `85/90`, `EMITTER_POSITION_OPTIONAL` was blank, formal C++ was blank, and the method inventory treated `0x004e8110` as if a callable helper method might exist.
  - Changed to: score `88/91`, `EMITTER_POSITION_OPTIONAL:0`, and a formal declaration-level class shell with `[[CHILDREN]]`, friend access for the candidate/composition panes, root focus/child fields, and `extern IMEPane *g_pIMEPane`; the `0x004e8110` row is now a target-specific no-code raw-helper proof rather than a source method declaration.
  - Summary/evidence: accepted B008 report, current MCP no-xref/no-function evidence for `0x004e8110`, existing [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) inline focus-caret behavior, [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) active-child candidate clamping evidence, and `g_pIMEPane` xrefs/storage evidence.
- 2026-06-08 A001 Batch131 focus/destructor split:
  - Before: score was `82/88`.
  - Changed to: score `85/90`.
  - Summary/evidence: exact child pages [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) and [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md) now document the raw focus/caret helper and scalar deleting destructor with live IDA caller/callee/disassembly evidence; [UID:00031H][0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper](by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md) documents the associated file-local singleton cleanup helper.
- 2026-06-17 B003 support update:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) and [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) now jointly resolve `focusPaneList`, `focusPaneCount`, `focusCaretAnchorY`, and `focusCaretAnchorX` for the root IME pane.
- 2026-06-17 B001 support update:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) now documents `+0xfc` as the root active child/popup pane pointer used by candidate-list vertical clamping.
- Completion/confidence score update: existed before as `0/0`; changed to `82/88`. Summary: process-level IME coordinator role, singleton, focus list, composition/candidate child lifecycle, methods, startup/focus xrefs, and storage evidence are documented with strong confidence; remaining gaps are mainly full internal field naming and final C++ reconstruction. Evidence: `IMEPaneFamily`, `IMECandidateQueueAndDestructors`, `IMEAdjustorThunks`, `g_pIMEPane`, and InputMan references.
- 2026-06-05: Marked reconstructable and attached to [UID:0000K5][IMEPanes](by-file/IMEPanes.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the process-level IME pane coordinator unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000K5`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004e7f20`, `0x004e8000`, `0x004e80a0`, `0x004e81a0`, `0x004e81b0`, `0x004e85b0`, and `0x004e8720`; constructor caller remains the application startup path at `0x004f639e`. The class score `82/88` and parent score `88/82` meet the 80/80 attachment gate.
