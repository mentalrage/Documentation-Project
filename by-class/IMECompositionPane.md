*** UID:00006G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "IMEPanes.h"
#include "../ui/core/Event.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/core/Pane.h"

class Event;
class IMEPane;

class IMECompositionPane : public Pane
{
public:
    IMECompositionPane();
    virtual ~IMECompositionPane();

    void SetCompositionString(const wchar_t *text, int length);
    int GetCompositionWidth() const;

protected:
    virtual bool OnMouseEvent(const Event *event);
    virtual bool OnKeyEvent(const Event *event);
    virtual void OnPaint();

private:
    int compositionCursorX;                  // +0xf8
    wchar_t compositionText[256];            // +0xfc
    bool compositionDragActive;              // +0x2fc
    int compositionDragStartY;               // +0x300
    int compositionDragStartX;               // +0x304
    unsigned char compositionDragSavedMode;  // +0x308
};

typedef char IMECompositionPaneSizeMustBe780[
    sizeof(IMECompositionPane) == 0x30c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# IMECompositionPane

## UID00029O IME-Layer Dependency - 2026-07-21

The constructor consumes independent [UID:0004VG][g_pIMEPaneLayer](by-global/g_pIMEPaneLayer.md). Pane inheritance, composition cursor/text/drag fields, zero bounds, pane order, root inline-equivalent evidence, methods, vtable, formal declaration, and non-initialized drag-start/saved-mode fields remain unchanged. Dated aggregate spellings are historical and superseded only as to this dependency expression.

## Status

- Likely source file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Address range: [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md), with destructor wrappers in [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- Current formal source route: the complete class declaration, exact `0x30c` layout guard, and method declarations are in `RECONSTRUCTION_H`; `RECONSTRUCTION_CPP` includes `IMEPanes.h` and `Event.h` before routing source methods, including the single empty UID0004C2 ordinary destructor. Older recovered views that placed `SetCompositionString` in `class_FittingRoomDownloadControlPane.cpp` are historical owner pollution. UID00031J is class-owned binary evidence but is non-reconstructable and non-emitting.
- Confidence: very strong for behavior, exact `0x30c` layout, ownership, ordinary-destructor source, compiler-wrapper exclusion, and the corrected IMEPanes header/source route.

## Class Purpose

`IMECompositionPane` displays the active IME composition string near the text caret. It supports dragging the composition popup, accepts composition text from key/IME messages, measures and clamps popup geometry, stores the text buffer, and paints the composition string plus caret rectangle.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `IMECompositionPane` | [UID:0004C1][0x004e7380-0x004e744d.IMECompositionPaneConstructor](by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md) | `88/91`; formal C++ populated. Constructs `Pane(0)`, clears `compositionCursorX`, zeroes `compositionText[256]`, clears `compositionDragActive`, attaches zero bounds to `g_pIMEPaneLayer`, and calls `SetPaneOrder(NULL, NULL)`. |
| `~IMECompositionPane` | [UID:0004C2][0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor](by-memory/0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor.md) | `88/91`; formal empty source destructor populated. MCP shows the 0x1f ordinary destructor restoring three `IMECompositionPane` vtables and tail-jumping to inherited `Pane` teardown; scalar delete-flag behavior remains [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md). |
| `SetCompositionString` | [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) | `88/91`; formal C++ populated. Measures text, finds focused text-edit caret, positions/clamps composition popup, copies text, updates `compositionCursorX`, and invalidates. |
| `OnMouseEvent` | [UID:0004C3][0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent](by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md) | `88/91`; formal C++ populated. Handles type `0` drag-move bounds translation, type `1` drag-start hit testing and mode save/temporary mode change, type `3` drag-end mode restore, and root `g_pIMEPane` focus-anchor updates. |
| `OnKeyEvent` | [UID:0004C4][0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent](by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md) | `88/91`; formal C++ populated. Vtable-only key handler at secondary slot `0x0061c444`; after compiler `this-0xa0` normalization, returns `false` except for Event type `13` composition result/commit, then forwards Event `+0x0a` UTF-16 text and `+0x09` length byte to `SetCompositionString`. |
| `OnPaint` | [UID:0004C5][0x004e7840-0x004e7912.IMECompositionPaneOnPaint](by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md) | `88/91`; formal C++ populated. Clears inherited `m_drawMode`, fills and frames `m_bounds`, draws counted `compositionText`, and fills a one-pixel caret rectangle from `compositionCursorX`. |
| `GetCompositionWidth` | [UID:0004C6][0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth](by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md) | `88/91`; formal C++ populated. Returns `compositionCursorX` at `+0xf8`; MCP proves exact bytes `8b 81 f8 00 00 00 c3` (`mov eax, [ecx+0F8h]; retn`), with no side effects and no direct xrefs/pointer-byte match as a confidence caveat. |
| `ScalarDeletingDestructor` | [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md) | `92/94`; exact class-owned MSVC compiler wrapper, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal. Its 85-byte body restores primary/secondary/tertiary views, enters through the primary vtable or `this-0xa0`/`this-0xa4` adjustors, calls Pane teardown, interprets hidden delete flags, uses MemoryMan-backed storage free on the normal delete path, and reaches a one-byte no-op on the bit-4 path. Human source remains only UID0004C2 and this class's `virtual ~IMECompositionPane();` declaration. |

## Observed State

```text
IMECompositionPane
  +0x0f8  compositionCursorX / cached composition cursor pixel width
  +0x0fc  wchar_t compositionText[256]
  +0x2fc  compositionDragActive / nonzero while composition popup drag is active
  +0x300  compositionDragStartY / Event mouse Y at left-button drag start
  +0x304  compositionDragStartX / Event mouse X at left-button drag start
  +0x308  compositionDragSavedMode / saved inherited Pane mode byte restored on release
```

[UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) now resolves these field roles: the constructor clears the 256-wide-character buffer, `SetCompositionString` copies into it with a 255-code-unit cap and explicit trailing nul, `InputMan::GetCompositionCursorPosition` supplies the cursor position used for the measured `compositionCursorX`, `OnPaint` uses `compositionCursorX` for the caret rectangle, and `GetCompositionWidth` returns the same cached x coordinate.

[UID:0004C3][0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent](by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md) resolves the four drag fields: constructor MCP evidence clears `+0x2fc`, mouse-down initializes `+0x300/+0x304/+0x308`, mouse-move reads the drag-start coordinates to translate bounds, and mouse-up restores the saved `m_mode` through `Pane::SetMode` before clearing active state.

## Evidence Notes

- 2026-08-13 B007 UID00031I accepted source-route callback moves the existing complete declaration from formal CPP to formal H so `IMECandidatePane` method definitions can make the source-level `IMECompositionPane::GetCompositionWidth()` call with a complete type available from `IMEPanes.h`. The formal H preserves every accepted method and field, includes `Pane.h`, forward-declares `Event` and `IMEPane`, and adds the exact `sizeof(IMECompositionPane) == 0x30c` guard corroborated by UID00031J and the final field at `+0x308`.
- The corrected formal CPP contains only `#include "IMEPanes.h"`, `#include "../ui/core/Event.h"`, and `[[CHILDREN]]`. It removes the former CPP-local declaration while retaining every composition child and historical evidence. Coherent generated refresh/readback remains supervisor-owned; B007 does not edit generated files.
- IDA MCP confirms all listed function starts and sizes.
- IDA xrefs to `0x004e7470` show the direct caller is `IMECompositionPane::OnKeyEvent` at `0x004e782d`.
- Current coverage/generation owns `0x004e7470` through this `IMECompositionPane` class. Historical generated source once owned it through `FittingRoomDownloadControlPane`; B003 source-quality reanalysis rejects that route because the body references [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md), text-edit caret helpers, screen bounds, and the composition text buffer, with no fitting-room state.
- 2026-05-26 recheck records exact helper and storage pages for [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) and [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md).
- Historical 2026-06-08 A001 Batch131 split [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md) as the exact scalar deleting destructor reached by composition-pane adjustor thunks at `0x004e85f2` and `0x004e85fd`.
- Historical child-gate state was `85/89` for UID00031J and `85/88` for this class. B004's 2026-07-15 target pass supersedes only that wrapper score/disposition: UID00031J is now `92/94`, class-owned, false, non-emitting, and blank. This class remains `88/91` because all unrelated method/source quality is unchanged.
- B004 2026-07-15 live evidence on database `4ef1c645` proves UID00031J's exact SHA256 `70A98560325CFF07AF2772F37D414ED4B7A86470F90BB097B6396E2FF3DBBF8D`, three class vptrs at `0x0061c3ec/0x0061c438/0x0061c468`, composition adjustors with `this-0xa0` and `this-0xa4`, hidden bit-1/bit-4 delete behavior, complete-object size `0x30c` / 780, and one-byte no-op `0x0041b6a0` branch. The target has no unique derived cleanup and therefore emits no source.
- 2026-06-30 B008 callback adds the formal class declaration shell with `[[CHILDREN]]`, preserving the populated [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) child and carrying the proven `compositionCursorX +0xf8` and `compositionText[256] +0xfc` fields into generated source shape.
- 2026-06-30 B009 callback adds [UID:0004C3][0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent](by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md) as a populated formal-C++ child. Current MCP evidence proves the secondary vtable slot at `0x0061c43c`, exact size `0x1c9`, padding `0x004e7809-0x004e7810`, branch behavior for Event types `0/1/3`, drag fields `+0x2fc/+0x300/+0x304/+0x308`, inherited Pane mode/bounds/origin dependencies, and root `g_pIMEPane` anchor writes at `0x004e7689`, `0x004e77c2`, and `0x004e77d3`.
- 2026-07-01 B004 UID0004C4 implementation callback adds [UID:0004C4][0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent](by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md) as a populated formal-C++ child. MCP session `supervisor_resume_20260629` proves `sub_4E7810` exact size `0x28`, predecessor padding `0x004e7809-0x004e7810`, successor padding `0x004e7838-0x004e7840`, secondary vtable cell `0x0061c444`, no direct code callers, single callee UID00018A at `0x004e782d`, Event type `13`, payload offsets `+0x09/+0x0a`, Event factory `0x004a9cb0` support, and compiler `this-0xa0` secondary-view normalization.
- 2026-07-01 B005 UID0004C6 implementation callback adds [UID:0004C6][0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth](by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md) as a populated formal-C++ child. MCP session `supervisor_resume_20260629` proves exact size `0x7`, body bytes `8b 81 f8 00 00 00 c3`, `mov eax, [ecx+0F8h]; retn`, padding after [UID:0004C5][0x004e7840-0x004e7912.IMECompositionPaneOnPaint](by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md) and before [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md), and a unique byte-pattern match. The method returns accepted field `compositionCursorX +0xf8`; [UID:0004C7][0x004e7b70-0x004e7cae.IMECandidatePaneConstructor](by-memory/0x004e7b70-0x004e7cae.IMECandidatePaneConstructor.md) supports the source use because its optimized binary reads active child `+0xf8` while generated C++ calls `compositionPane->GetCompositionWidth()`. Zero xrefs and no `20 79 4E 00` pointer-byte match are preserved as confidence caveats, not no-code proof.
- 2026-06-30 B008 UID0004C5 implementation callback adds [UID:0004C5][0x004e7840-0x004e7912.IMECompositionPaneOnPaint](by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md) as a populated formal-C++ child. MCP evidence from session `supervisor_resume_20260629` confirms `sub_4E7840` size `0xd2`, vtable cell `0x0061c430`, no direct code callers, padding before/after, inherited draw-mode clear at `+0x70`, bounds fill/frame sequence, `compositionText` counted UTF-16 draw, and `compositionCursorX`-based one-pixel caret fill. The child uses accepted GrafPort names `SetDrawColor`, `SetTextColor`, `MoveTo`, `DrawRectFrame`, `DrawWideText`, `GetLineHeight`, and source-facing `FillRect` for Surface slot `0x0069b3fc`.
- 2026-06-30 B010 UID0004C2 implementation callback adds [UID:0004C2][0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor](by-memory/0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor.md) as a populated formal-C++ child. Current MCP session `supervisor_resume_20260629` proves `sub_4E7450` size `0x1f`, vtable stores at `0x004e7450`, `0x004e7456`, and `0x004e7460` to `0x0061c3ec`, `0x0061c438`, and `0x0061c468`, tail transfer at `0x004e746a` to inherited `Pane` teardown `0x00544580`, and zero inbound xrefs as a reachability caveat rather than no-code proof. Constructor and scalar-wrapper parity tie the same vtables to [UID:0004C1][0x004e7380-0x004e744d.IMECompositionPaneConstructor](by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md) and [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md). The source body is intentionally empty because the derived fields are POD/inline storage and base teardown is compiler-generated. The class formal block keeps `[[CHILDREN]]` so this destructor emits through this class into [UID:0000K5][IMEPanes](by-file/IMEPanes.md).
- 2026-07-01 B007 UID0004C1 implementation callback adds [UID:0004C1][0x004e7380-0x004e744d.IMECompositionPaneConstructor](by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md) as a populated formal-C++ child. MCP evidence proves `sub_4E7380` size `0xcd`, half-open range `0x004e7380-0x004e744d`, five-byte predecessor and three-byte successor `0xcc` padding, base `Pane(0)` construction, compiler-only primary/secondary/tertiary vtable stores, `compositionCursorX = 0`, `memset(compositionText, 0, sizeof(compositionText))`, `compositionDragActive = false`, zero-bounds `InitRectBounds`, `AddToLayer(..., g_mainUiLayerSlots.fpsOverlayLayerContext)`, `SetPaneOrder(NULL, NULL)`, zero direct xrefs as a caveat, and inline duplication in `IMEPane::HandleIMEMessage`. Drag-start Y/X and saved-mode fields are initialized by [UID:0004C3][0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent](by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md) mouse-down, not by the constructor.

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md)
- [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md)
- [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md)
- [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)

## Changes

- 2026-08-13 B007 UID00031I accepted source-route implementation callback:
  - Before: `88/91`; owner/emitter UID0000K5 and position `0` were correct, but the complete `IMECompositionPane` declaration was stored in formal CPP and formal H was blank, leaving the candidate constructor's source-level `GetCompositionWidth()` dependency without a complete header-visible type.
  - Changed to: `90/92`, preserving owner/emitter UID0000K5, reconstructable true, position `0`, all method/field/destructor/wrapper/history evidence, and all method children. The exact declaration and `0x30c` size guard now occupy formal H; formal CPP now includes the self-header and Event dependency before `[[CHILDREN]]`.
  - Summary/evidence: the established field sequence through `compositionDragSavedMode +0x308`, exact complete size `0x30c`, candidate-constructor source call, one UID0004C2 ordinary destructor definition, and zero UID00031J wrapper output resolve the header order without changing behavior or duplicating a class definition in CPP.
- 2026-07-15 B004 UID00031J implementation callback:
  - Preserved: class score `88/91`, owner/emitter UID0000K5, reconstructable true, position 0, all fields/methods, and the complete managed class block including `virtual ~IMECompositionPane();` and `[[CHILDREN]]`.
  - Changed support text: the UID00031J row and evidence now record `92/94`, class-owned but false/non-emitting/blank, exact three-view/adjustor/hidden-flag/object-size/helper facts, and sole human-source coverage by UID0004C2. Historical `85/89` child-gate language is time-scoped rather than presented as current.

- 2026-07-01 B005 UID0004C6 implementation callback:
  - Changed support text without changing this class score or disturbing existing child details.
  - Summary/evidence: [UID:0004C6][0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth](by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md) now emits formal `IMECompositionPane::GetCompositionWidth() const` C++ through this class. The method row and evidence notes preserve exact `0x7` range, bytes `8b 81 f8 00 00 00 c3`, `compositionCursorX +0xf8`, checked padding, candidate-constructor source use, generated output route through [UID:0000K5][IMEPanes](by-file/IMEPanes.md), and the no-xref/no-pointer-byte confidence caveat.
- 2026-07-01 B004 UID0004C4 implementation callback:
  - Changed support text without changing this class score or disturbing existing child details.
  - Summary/evidence: [UID:0004C4][0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent](by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md) now emits formal `IMECompositionPane::OnKeyEvent(const Event *event)` C++ through this class. The method row and evidence notes preserve the accepted proof for exact `0x28` range, padding, vtable xref `0x0061c444`, no direct callers, single callee UID00018A, Event type `13`, payload offsets `+0x09/+0x0a`, Event factory `0x004a9cb0` support, secondary-view `this-0xa0` normalization, and rejected InputMan/Event/Pane/no-code/sibling-merge alternatives.
- 2026-07-01 B007 UID0004C1 implementation callback:
  - Changed support text without changing this class score or disturbing existing child details.
  - Summary/evidence: [UID:0004C1][0x004e7380-0x004e744d.IMECompositionPaneConstructor](by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md) now emits formal `IMECompositionPane::IMECompositionPane()` C++ through this class. The method row and evidence notes preserve the accepted proof for exact size `0xcd`, range/padding, `Pane(0)`, compiler-only vtable stores, `compositionCursorX`/`compositionText[256]`/`compositionDragActive` initialization, non-initialization of drag-start/saved-mode fields, zero-bounds layer attach to `g_mainUiLayerSlots.fpsOverlayLayerContext`, `SetPaneOrder(NULL, NULL)`, zero-xref caveat, and root handler inline duplication.
- 2026-06-30 B008 UID0004C5 implementation callback:
  - Changed support text without changing this class score or B009's drag-field additions.
  - Summary/evidence: [UID:0004C5][0x004e7840-0x004e7912.IMECompositionPaneOnPaint](by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md) now emits formal `IMECompositionPane::OnPaint` C++ through this class. The method row and evidence notes now preserve the accepted live MCP proof for exact size `0xd2`, vtable slot `0x0061c430`, no direct code callers, background/frame/text/caret draw sequence, `compositionText`/`compositionCursorX` consumption, and rejected raw helper/no-code alternatives.
- 2026-06-30 B010 UID0004C2 implementation callback:
  - Changed support text without changing this class score.
  - Summary/evidence: [UID:0004C2][0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor](by-memory/0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor.md) now emits formal `IMECompositionPane::~IMECompositionPane()` C++ through this class. The method row and evidence notes preserve current MCP proof for exact size `0x1f`, vtable stores at `0x004e7450/0x004e7456/0x004e7460`, inherited `Pane` teardown transfer at `0x004e746a`, zero inbound xrefs as a caveat, scalar wrapper separation from [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md), and the source-shape decision that vtable/base/delete logic remains compiler-generated.
- 2026-06-30 B009 implementation callback:
  - Before: score was `87/90`, the formal class shell stopped after `compositionText[256]`, and `OnMouseEvent` was only a broad drag/mode row with no populated child-body status.
  - Changed to: score `88/91`, added `compositionDragActive`, `compositionDragStartY`, `compositionDragStartX`, and `compositionDragSavedMode` to the formal shell and observed-state table, and updated the `OnMouseEvent` method row/evidence notes for [UID:0004C3][0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent](by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md) formal C++.
  - Summary/evidence: accepted B009 report `0004C3-IMECompositionPaneOnMouseEvent-source-quality.md`; current MCP `decompile/analyze_function/disasm` confirms Event type `0/1/3` drag behavior, constructor clears drag-active byte `+0x2fc`, target writes/reads `+0x2fc/+0x300/+0x304/+0x308`, and the method uses inherited `Pane::SetMode`, bounds/origin, and `g_pIMEPane` focus anchors.
- 2026-06-30 B008 implementation callback:
  - Before: score was `85/88`, `EMITTER_POSITION_OPTIONAL` was blank, and formal C++ was blank despite populated [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) output.
  - Changed to: score `87/90`, `EMITTER_POSITION_OPTIONAL:0`, and a formal declaration-level class shell with `[[CHILDREN]]`, constructor/destructor and handler prototypes, `compositionCursorX`, and `compositionText[256]`.
  - Summary/evidence: accepted B008 report, existing B003 [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) formal C++, current status of this class as [UID:0000K5][IMEPanes](by-file/IMEPanes.md) child, and current MCP composition-field evidence.
- 2026-06-08 A001 Batch131 scalar-destructor split:
  - Before: score was `80/86`.
  - Changed to: score `85/88`.
  - Summary/evidence: exact child page [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md) now documents the scalar deleting destructor with live IDA caller/callee evidence, closing the strict direct-parent gate for that child.
- 2026-06-17 B003 source-quality update:
  - Changed support state without changing this class score.
  - Summary/evidence: [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) is now `88/91` with formal C++; B003 resolved the `compositionCursorX` and `compositionText[256]` fields, rejected the stale fitting-room owner route, validated the active `IMEPanes.cpp` emitter route, and tied the method to `OnKeyEvent`, `g_pIMEPane`, TextEdit caret helpers, screen clamping, and `InputMan::GetCompositionCursorPosition`.
- Completion/confidence score update: existed before as `0/0`; changed to `80/86`. Summary: composition popup purpose, constructor/destructor/set-string/mouse/key/paint methods, generated-owner correction, text-edit caret relationship, and singleton storage are documented with strong confidence; remaining work is detailed field naming and final C++ reconstruction. Evidence: `IMEPaneFamily`, `IMECompositionSetCompositionString`, `IMEAdjustorThunks`, `g_pIMEPane`, TextEditPane, and FittingRoom caveat references.
- 2026-06-05: Marked reconstructable and attached to [UID:0000K5][IMEPanes](by-file/IMEPanes.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the IME composition pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000K5`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004e7380`, `0x004e7450`, `0x004e7470`, `0x004e7640`, `0x004e7810`, `0x004e7840`, `0x004e7920`, and `0x004e86c0`, with `SetCompositionString` called from `0x004e782d`. The class score `80/86` and parent score `88/82` meet the 80/80 attachment gate.
