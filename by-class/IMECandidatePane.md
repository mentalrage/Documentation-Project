*** UID:00006F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "IMEPanes.h"
#include "InputMan.h"
#include "../ui/core/Event.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../ui/core/Pane.h"

#include <deque>
#include <string>

class Event;
class IMEPane;

typedef std::deque<std::wstring> CandidateStringList;

class IMECandidatePane : public Pane
{
    friend class IMEPane;

public:
    IMECandidatePane();
    virtual ~IMECandidatePane();

    void ShowCandidateList(const Event *event);

protected:
    virtual bool HandleIMEMessage(const Event *event);
    virtual void OnPaint();

private:
    CandidateStringList visibleCandidates;  // +0xf8, display-side visible candidate strings.
    int selectedCandidateRow;               // +0x10c, selected row within the visible page.
    int candidateAnchorY;                   // +0x110, top anchor copied from the root IME pane.
    int candidateAnchorX;                   // +0x114, left anchor copied from the root IME pane.
};

typedef char IMECandidatePaneSizeMustBe280[
    sizeof(IMECandidatePane) == 0x118 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# IMECandidatePane

## UID00029O IME-Layer Dependency - 2026-07-21

The constructor consumes independent [UID:0004VG][g_pIMEPaneLayer](by-global/g_pIMEPaneLayer.md). Pane inheritance, `visibleCandidates` construction, selected-row and anchor behavior, no-SetPaneOrder negative, root inline-equivalent reachability, methods, vtable, and formal declaration remain unchanged. Dated aggregate expressions remain historical evidence but are superseded as current source shape.

## UID0000K6 InputMan Header Dependency - 2026-08-24

- This first CPP-emitting IMEPanes fragment includes `InputMan.h` immediately after `IMEPanes.h`. IMEPanes code calls the free `GetCompositionCursorPosition()` declaration owned by InputMan.h; a forward declaration or duplicate local prototype would weaken the accepted source contract.
- The include changes only declaration visibility. IMECandidatePane ownership/emitter UID0000K5, source position `0`, score `92/94`, complete H declaration, Event dependency, and all method children remain unchanged.

## Status

- Likely source file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Address range: [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md), with queue/destructor support in [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- Historical recovered-file views placed the class in `source-3/simroot_v2/class_IMECandidatePane.cpp` and `ShowCandidateList` in `class_FittingRoomDownloadControlPane.cpp`; those are owner-polluted recovery artifacts, not the accepted source route.
- Current formal source route: the complete class declaration, `CandidateStringList` alias, required includes/forwards, member order, and `0x118` size guard are in `RECONSTRUCTION_H`; `RECONSTRUCTION_CPP` includes `IMEPanes.h`, `InputMan.h`, and `Event.h` before routing method children. This prevents a CPP-local duplicate class definition and supplies the free InputMan cursor-helper declaration.
- Confidence: very strong for behavior, exact `0x118` layout, ownership, ordinary-destructor source, compiler-wrapper exclusion, and the corrected IMEPanes header/source route.

## Class Purpose

`IMECandidatePane` displays the IME candidate list. It owns popup geometry, selected index, source-facing `CandidateStringList visibleCandidates` (`std::deque<std::wstring>`-style), candidate message dispatch, and painting of selected/unselected candidate rows. The virtual destructor declaration in this class and sole ordinary definition UID00031F are the complete human destruction source; scalar wrapper UID00031I and its adjustors are compiler ABI output only.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ShowCandidateList` | [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) | `87/90`; consumes Event type `15`, measures visible candidate strings, positions/clamps popup, copies the visible candidate range into local queue, stores selected row, and invalidates. |
| `IMECandidatePane` | [UID:0004C7][0x004e7b70-0x004e7cae.IMECandidatePaneConstructor](by-memory/0x004e7b70-0x004e7cae.IMECandidatePaneConstructor.md) | `88/91`; formal C++ populated. Constructs `Pane(0)`, default-constructs the `visibleCandidates` deque, attaches zero bounds to `g_pIMEPaneLayer`, sets `selectedCandidateRow = -1`, initializes candidate anchors from the active composition child bounds plus `IMECompositionPane::GetCompositionWidth()` or defaults both anchors to `4`, preserves no-`SetPaneOrder` negative evidence, and keeps zero direct constructor xrefs as a caveat resolved by root handler inline duplication. |
| `~IMECandidatePane` | [UID:00031F][0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor](by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md) | `91/94`; sole human destructor definition. Exact 76-byte raw body restores all three candidate vtable views, clears `visibleCandidates`, releases/nulls its proxy at `+0xf8`, and transfers to inherited Pane teardown; formal source remains the existing minimal destructor body. |
| `HandleIMEMessage` | [UID:0004C8][0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage](by-memory/0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage.md) | `88/91`; formal C++ populated. Returns `false` unless Event `+0x04` is candidate-list type `15`, then forwards the original event to `ShowCandidateList(event)` and returns `true`; binary output performs the secondary-to-primary `this-0xa0` adjustment before calling UID00018B at `0x004e7d13`. |
| `OnPaint` | [UID:0004C9][0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint](by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md) | `88/90`; emits formal C++ through this class route, fills/draws the popup frame, iterates `visibleCandidates`, and draws selected-row highlighting based on `selectedCandidateRow`. |
| Compiler scalar deleting destructor | [UID:00031I][0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor](by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md) | `92/94`, class-owned but `RECONSTRUCTABLE:FALSE`, non-emitting, and blank formal CPP/H. Exact 127-byte wrapper duplicates UID00031F cleanup, receives four-byte hidden flags, conditionally frees complete storage, carries size `0x118` on its bit-4 one-byte no-op path, and contributes no handwritten method. |

## Observed Candidate State

| Offset | Best current role | Evidence |
| --- | --- | --- |
| `+0xf8` | visible candidate deque/list member | [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) assigns the Event `+0x08` visible candidate range into this member through the IME candidate deque helper; [UID:0004C9][0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint](by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md) traverses the same deque via `+0xf8/+0x104/+0x108` to draw each candidate row. |
| `+0x10c` | selected candidate row within the visible page | [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) stores Event `+0x0c`, which B001 traces to `dwSelection - pageStart` in `InputMan`; [UID:0004C9][0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint](by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md) compares the current row index against this field to choose the highlighted row. |
| `+0x110` | candidate popup anchor Y | Current MCP decompile of [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) uses `this[68]` as the popup top and vertical clamp anchor. |
| `+0x114` | candidate popup anchor X | Current MCP decompile uses `this[69]` as the popup left and horizontal screen-width clamp anchor. |

Treat `CandidateStringQueue` as generated/STL-helper naming for a `std::deque<std::wstring>`-style member unless later evidence finds handwritten product behavior outside the documented deque helper ranges.

The final documented member at `+0x114` occupies four bytes, so the complete candidate-pane size is `0x118` / 280. UID00031I independently carries the same size on its hidden bit-4 runtime path, corroborating the class tail without adding a source field or wrapper method.

`OnPaint` [UID:0004C9][0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint](by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md) consumes `visibleCandidates`, `selectedCandidateRow`, inherited `bounds`, and inherited GrafPort-style draw helpers. It does not read `candidateAnchorX` or `candidateAnchorY`; those anchor fields are setup/layout state used by `ShowCandidateList` when positioning the popup.

[UID:0004CE][0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage](by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md) calls the candidate pane secondary IME handler after lazily constructing `IMEPane::candidatePane`. The class shell grants `friend class IMEPane` so the accepted source-level root handler can call protected `HandleIMEMessage(const Event *event)` while preserving the protected virtual method model documented for this candidate pane.

## Evidence Notes

- 2026-08-13 B007 UID00031I accepted source-route callback moves the complete declaration from formal CPP to formal H without changing runtime behavior. `Pane` is a complete `0xf8` base; constructor writes cover the deque object at `+0xf8..+0x108`, selected row at `+0x10c`, Y anchor at `+0x110`, and X anchor at `+0x114`; UID00031I independently carries complete size `0x118`. The formal H therefore includes `Pane.h`, `<deque>`, and `<string>`, forward-declares `Event` and `IMEPane`, preserves the established declaration/member spelling, and adds an exact `sizeof(IMECandidatePane) == 0x118` guard.
- The corrected formal CPP contains `#include "IMEPanes.h"`, `#include "InputMan.h"`, `#include "../ui/core/Event.h"`, and `[[CHILDREN]]`. It deliberately removes the former CPP-local class declaration so generated source has one declaration in the header and method definitions in the CPP; InputMan.h supplies the cross-file cursor helper.
- IDA MCP confirms all listed function starts and sizes.
- 2026-05-26 IDA MCP recheck shows `0x004e7930` is directly called by `IMECandidatePane::HandleIMEMessage` at `0x004e7d13`.
- Current generated source owns `0x004e7930` through `FittingRoomDownloadControlPane`; the function copies IMM candidate strings into `CandidateStringQueue` and updates candidate pane geometry, so it should be treated as IME candidate ownership.
- 2026-05-26 IDA MCP follow-up identifies the generated `CandidateStringQueue` helper bodies as MSVC/Dinkumware [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md) support. Source reconstruction should keep the member as a normal candidate-string container, likely `std::deque<std::wstring>`, not a handwritten product queue.
- `class_IMECandidatePane.cpp.disabled` omits adjustor thunk `0x004e85e7`; IDA confirms it delegates to the scalar deleting destructor with a secondary-subobject adjustment.
- The exact [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md), [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md), and [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md) pages should be preferred over generated fitting-room owner names.
- 2026-06-08 A001 Batch131 split the candidate-pane cleanup bodies into exact pages. [UID:00031F][0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor](by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md) is the raw ordinary destructor between `0x004e7b70` and `0x004e7d00`; [UID:00031I][0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor](by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md) is reached by the two candidate adjustor thunks and handles scalar deletion.
- Historical 2026-06-08 child assignment was justified at the then-current `85/85` child and `85/89` class gates. Current scores and dispositions supersede only those numbers: UID00031F is `91/94`, UID00031I is `92/94` false/non-emitting, and this class is `90/93` with the same candidate-list, queue, destructor, and source-file parent evidence preserved.
- 2026-08-11 B007 destructor reanalysis closes the former source/output ambiguity. UID00031F is `[0x004e7cb0,0x004e7cfc)`, SHA256 `E6E6B5ECF5F1F161768923135BC4C645B378C955F4FBF59B39B7BC4C9A2FDA2E`, and remains the sole human definition. UID00031I is `[0x004e8640,0x004e86bf)`, SHA256 `6D7E5BAF5E4F865F49CFDB7A41F0E4EA699C3EDCF9D7DA675EC267263FB895EF`, and repeats the same three vptr restores, candidate-container clear, proxy release/null, and Pane teardown before compiler-only hidden-flag handling.
- UID00031I's live routes are primary candidate vtable `0x0061c474` and two exact 11-byte adjustors from secondary/tertiary cells `0x0061c4c0` and `0x0061c4f0`. It has no ordinary caller. These routes prove virtual-destructor ABI liveness and the `+0/+0xa0/+0xa4` class views, not a source-visible scalar-wrapper member.
- The hidden mask matrix is exact: mask `0x1` clear returns after destruction, mask `0x1` set with `0x4` clear calls the project operator-delete wrapper, and both bits set carry size `0x118` to a one-byte runtime no-op before returning `this`. Vector/sized-delete and handwritten wrapper interpretations are rejected.
- The accepted generated-source contract is one class declaration with `virtual ~IMECandidatePane();`, one UID00031F definition, and no UID00031I marker, proof comment, pseudo-body, hidden flag, explicit vptr/helper/delete call, or empty-emitter marker. Historical proof-comment output is retained only in dated documentation history.
- 2026-06-17 B001 source-quality reanalysis raises [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) to `87/90` and closes the main candidate-display blockers. The method is reached from `IMECandidatePane::HandleIMEMessage` at `0x004e7d13` with a `this-0xa0` secondary-subobject adjustment, consumes Event type `15`, reads the visible candidate deque pointer from Event `+0x08`, reads selected row from Event `+0x0c`, rejects historical FittingRoom ownership, and uses root `g_pIMEPane+0xfc` only for active child/popup clamping.
- 2026-06-30 B008 current MCP callback updates the class shell and field order: `CandidateStringList visibleCandidates` is the source-facing `std::deque<std::wstring>`-style member at `+0xf8`, `selectedCandidateRow` is at `+0x10c`, `candidateAnchorY` is at `+0x110`, and `candidateAnchorX` is at `+0x114`. This corrects the older X/Y wording by matching the decompiled top/left use in [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md).
- 2026-06-30 B010 implementation callback resolves [UID:0004C9][0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint](by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md) as an emitting child of this class: current MCP identifies `0x004e7d30` as a `0x1ea` byte virtual paint body with vtable data xref `0x0061c4b8`, accepted GrafPort helper calls to `SetDrawColor`, `SetTextColor`, `MoveTo`, `DrawRectFrame`, `GetLineHeight`, and `DrawWideText`, inferred fill helper `FillRect` for external `0x0069b3fc`, deque reads from `visibleCandidates`, and selected-row compare at `+0x10c`. Numeric color constants `143` and `128` remain exact but symbolically unnamed.
- 2026-07-01 B009 UID0004C7 implementation callback resolves [UID:0004C7][0x004e7b70-0x004e7cae.IMECandidatePaneConstructor](by-memory/0x004e7b70-0x004e7cae.IMECandidatePaneConstructor.md) as an emitting constructor child of this class. MCP identifies `sub_4E7B70` size `0x13e`, confirms four-byte predecessor padding and two-byte successor padding before the raw ordinary destructor, proves `Pane(0)`, compiler-only candidate vtable stores, default-construction lowering for `CandidateStringList visibleCandidates`, zero-bounds `AddToLayer(..., g_mainUiLayerSlots.fpsOverlayLayerContext)`, `selectedCandidateRow = -1`, active-child anchor derivation from bounds plus `IMECompositionPane::GetCompositionWidth()`, and default anchors of `4/4`. The constructor does not call `SetPaneOrder`; zero direct inbound xrefs are preserved as a caveat because [UID:0004CE][0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage](by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md) duplicates/inlines the same candidate construction sequence before storing and dispatching the candidate child.
- 2026-07-01 B010 UID0004CE implementation callback adds `friend class IMEPane` to support the accepted root dispatcher source body. UID0004CE reaches the candidate pane through the secondary IME handler after lazy construction and calls `candidatePane->HandleIMEMessage(event)` in source form; the friend declaration is the compile-safe route while keeping the handler protected.
- 2026-07-01 B004 UID0004C8 implementation callback resolves [UID:0004C8][0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage](by-memory/0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage.md) as an emitting protected handler child of this class without changing this class score. MCP identifies the exact `0x24` body, confirms Event `+0x04` compare against `0x0f`, false/true returns, and call to [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) at `0x004e7d13` after the `this-0xa0` ABI adjustment. MCP also verifies secondary-vtable slot `0x0061c4cc` stores `0x004e7d00`; zero direct code callers are expected for this virtual child. Event factory `0x004a9e50` and the InputMan candidate branch provide Event type `15`, visible-candidate deque/list pointer `+0x08`, selected row `+0x0c`, and tick `+0x10c`; the body rejects no-code, UID00018B merge, InputMan/Event owner, file-only, aggregate-only, generic Pane, and root IMEPane alternatives.

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md)
- [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md)
- [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md)
- [UID:00031F][0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor](by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md)
- [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md)
- [UID:00031I][0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor](by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md)
- [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)

## Changes

- 2026-08-24 B008 UID0000K6 accepted implementation callback: inserted exact `#include "InputMan.h"` immediately after `IMEPanes.h` in the first emitted CPP fragment and documented the `GetCompositionCursorPosition()` declaration dependency; retained all IMECandidatePane metadata, ownership, H route, methods, and behavior unchanged.

- 2026-08-13 B007 UID00031I accepted source-route implementation callback:
  - Before: `90/93`; owner/emitter UID0000K5 and position `0` were correct, but the complete `IMECandidatePane` declaration was stored in formal CPP, formal H was blank, and generated `IMEPanes.h` exposed only a forward declaration.
  - Changed to: `92/94`, preserving owner/emitter UID0000K5, reconstructable true, position `0`, every existing behavior/layout/destructor/history fact, and all method children. The exact complete declaration, dependency set, source-facing alias/member order, and `0x118` guard now occupy formal H; formal CPP now includes the self-header and Event dependency before `[[CHILDREN]]`.
  - Summary/evidence: exact Pane size `0xf8`, constructor writes through `+0x114`, UID00031I complete-size literal `0x118`, three candidate vtable views, UID00031F sole ordinary destructor source, and the compiler-only zero-output UID00031I route jointly establish the declaration and prevent a duplicate CPP-local class definition. Historical recovery/owner-polluted placements remain documented as superseded evidence.
- 2026-08-11 B007 UID00031I implementation callback:
  - Before: `88/90`; destructor rows identified ordinary/scalar behavior but did not carry exact parity, complete-object size, hidden-flag matrix, or the final no-duplicate source disposition.
  - Changed to: `90/93`, preserving owner/emitter UID0000K5, source position `0`, and the complete existing formal class declaration.
  - Summary/evidence: UID00031F `91/94` is the sole human destructor definition; UID00031I `92/94` is class-owned false/non-emitting compiler output. Exact hashes, three candidate vtable views, `visibleCandidates` cleanup, `0x118` layout, adjustor/vtable liveness, and hidden flag behavior now explain destruction without adding any wrapper source.
- 2026-07-01 B010 UID0004CE implementation callback:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:0004CE][0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage](by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md) now emits formal root dispatcher C++ that lazily constructs `IMEPane::candidatePane` and dispatches the original candidate-list event through `IMECandidatePane::HandleIMEMessage(event)`. Added `friend class IMEPane` so this root source body can call the protected candidate handler without changing the protected virtual method model or overwriting the accepted B009 UID0004C7 constructor evidence.
- 2026-07-01 B004 UID0004C8 implementation callback:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:0004C8][0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage](by-memory/0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage.md) now emits formal `IMECandidatePane::HandleIMEMessage(const Event *event)` C++ through this class. The method row/evidence preserve accepted `88/91`, exact `0x24` range, vtable slot `0x0061c4cc`, Event type `15` guard, false/true return paths, `this-0xa0` ABI adjustment, forwarding to UID00018B `ShowCandidateList`, Event factory/InputMan producer support, and rejected no-code/merge/alternate-owner routes.
- 2026-07-01 B009 UID0004C7 implementation callback:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:0004C7][0x004e7b70-0x004e7cae.IMECandidatePaneConstructor](by-memory/0x004e7b70-0x004e7cae.IMECandidatePaneConstructor.md) now emits formal `IMECandidatePane::IMECandidatePane()` C++ through this class. The method row and evidence notes preserve the accepted proof for exact size `0x13e`, range/padding, `Pane(0)`, compiler-only vtable/security-cookie/EH/deque-proxy lowering, source-level `CandidateStringList visibleCandidates` default construction, zero-bounds layer attach, `selectedCandidateRow = -1`, active-child/default candidate anchor behavior, no `SetPaneOrder`, zero-xref caveat, and root handler inline duplication. Added the `IMECompositionPane` forward declaration needed by the constructor source-level `GetCompositionWidth()` call.
- 2026-06-30 B010 implementation callback:
  - Before: score was `87/90`; this class listed `OnPaint` only as a role and did not record the accepted child body/field-use evidence.
  - Changed to: score `88/90`; [UID:0004C9][0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint](by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md) is recorded as an emitting `[[CHILDREN]]` child with formal C++, candidate deque traversal, selected-row highlight use, inherited `bounds`, and inherited GrafPort draw helper evidence.
  - Summary/evidence: B010 accepted report and current MCP session `supervisor_resume_20260629` prove the target function range/size, vtable xref, helper mapping, `visibleCandidates +0xf8/+0x104/+0x108`, and `selectedCandidateRow +0x10c`; class owner/emitter route remains [UID:0000K5][IMEPanes](by-file/IMEPanes.md), and the formal class block keeps `[[CHILDREN]]`.
- 2026-06-30 B008 implementation callback:
  - Before: score was `85/89`, `EMITTER_POSITION_OPTIONAL` was blank, formal C++ was blank, and the candidate anchor field order described `+0x110` as X and `+0x114` as Y.
  - Changed to: score `87/90`, `EMITTER_POSITION_OPTIONAL:0`, and a formal declaration-level class shell with `[[CHILDREN]]`, `CandidateStringList`, method prototypes, `visibleCandidates`, `selectedCandidateRow`, corrected `candidateAnchorY +0x110`, and corrected `candidateAnchorX +0x114`.
  - Summary/evidence: accepted B008 report with current MCP decompile of [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md), candidate deque support docs [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md) / [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md), and the confirmed [UID:0000K5][IMEPanes](by-file/IMEPanes.md) emitter route.
- 2026-06-08 A001 Batch131 cleanup split:
  - Before: score was `82/86`.
  - Changed to: score `85/89`.
  - Summary/evidence: exact child pages [UID:00031F][0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor](by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md) and [UID:00031I][0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor](by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md) now document the raw ordinary destructor and scalar deleting destructor with live IDA caller/callee/vtable evidence, closing the direct-parent gate for those children.
- 2026-06-17 B001 support update:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) is now `87/90`; the class page now records the visible-candidate deque, selected-row, and popup-anchor field roles plus the Event type `15` payload route from InputMan/Event.
- Completion/confidence score update: existed before as `0/0`; changed to `82/86`. Summary: candidate-list pane purpose, geometry/candidate queue behavior, methods, generated-owner correction, deque-template support, adjustor thunk caveat, singleton relationship, and exact memory pages are documented with strong confidence. Evidence: `IMEPaneFamily`, `IMECandidateShowCandidateList`, `IMECandidateQueueAndDestructors`, `IMEAdjustorThunks`, `g_pIMEPane`, and `CandidateStringDequeTemplate`.
- 2026-06-05: Marked reconstructable and attached to [UID:0000K5][IMEPanes](by-file/IMEPanes.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the IME candidate-list pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000K5`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004e7930`, `0x004e7b70`, `0x004e7d00`, `0x004e7d30`, and `0x004e8640`, with `ShowCandidateList` called from `0x004e7d13`. The class score `82/86` and parent score `88/82` meet the 80/80 attachment gate.
