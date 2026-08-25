*** UID:0000D6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "HelpPanes.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CONTROLS_HELPPANES_H
#define NEXUSTK_UI_CONTROLS_HELPPANES_H

#include "../core/Pane.h"
#include "../../util/Singleton.h"

class SimpleHelpPane : public Pane,
                       public Singleton<SimpleHelpPane>
{
public:
    SimpleHelpPane(const wchar_t *text,
                   Pane *owner,
                   int x,
                   int y,
                   int timeoutMs);
    virtual ~SimpleHelpPane();

    void Close(bool immediate);

protected:
    virtual void OnPaintFrame();
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    wchar_t *m_textBuffer;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SimpleHelpPane

## UID0000KA Header Consumer Closure - 2026-08-15

The class declaration now emits through the formal H channel into the owning `HelpPanes.h`; CPP is an include-plus-children shell. This exposes the existing constructor and inherited close route used by both InventoryPane help handlers without duplicating a class in CPP. `g_pSimpleHelpPane` remains owned by UID0000S9 under the same file route. The accepted InventoryPane include is therefore the physical owner header `../controls/HelpPanes.h`; no feature-local tooltip declaration is permitted.

## Status

- Source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: non-emitting split index [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) with exact source children [UID:00048E][0x004c6f90-0x004c7287.SimpleHelpPaneConstructor](by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md), [UID:00048F][0x004c7290-0x004c7307.SimpleHelpPaneDestructor](by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md), [UID:00048G][0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame](by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md), [UID:00048H][0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown](by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md), [UID:00048I][0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent](by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md), and [UID:00048J][0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress](by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Historical generated-output lead: `class_SimpleHelpPane.cpp`; use live IDA and linked by-* docs as scoring authority.
- Declaration state: complete source-facing class declaration at position `10`, with exact method children emitted afterward at positions `10/20/30/40/50/60` inside the class insertion point.
- Confidence: very strong for purpose, exact method cluster, Pane/Singleton inheritance, EBO layout, singleton lifecycle, vtable/read-only-data neighborhood, complete object size, HelpPanes source ownership, and corrected EventHandler/TimerHandler method roles. Exact original private/access/header spelling remains a cap; historical generated owner/type pollution is rejected as authority.

## Class Purpose

`SimpleHelpPane` is the older/simple timed text tooltip singleton. It copies a UTF-16 text buffer, measures multiline text, clamps a popup rectangle against parent and screen bounds, adds itself to the dialog/help layer, schedules a timer, and paints a bordered text popup.

## Inheritance And Layout

- Source inheritance is `SimpleHelpPane : public Pane, public Singleton<SimpleHelpPane>`. `Pane` already supplies the EventHandler and TimerHandler subobjects; they are not additional direct bases in the source declaration.
- RTTI hierarchy has seven entries and records nonvirtual `Singleton<SimpleHelpPane>` with PMD `mdisp=0xf8`, `pdisp=-1`, `vdisp=0`; secondary and tertiary complete-object offsets are `+0xa0` and `+0xa4`.
- Empty-base optimization allows the empty Singleton base and first derived data member to share `+0xf8`. Constructor allocation/copy, paint reads, and destructor release identify that member as `wchar_t *m_textBuffer`.
- The complete object is exactly `0xfc` bytes, corroborated by the scalar deleting destructor size guard. No explicit padding member or separate Singleton storage member is source-authored.
- `Singleton<SimpleHelpPane>` construction publishes the adjusted complete-object pointer and reverse base destruction clears it. Constructor/destructor source must not duplicate those stores.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SimpleHelpPane` | [UID:00048E][0x004c6f90-0x004c7287.SimpleHelpPaneConstructor](by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md) | Position `10`; initializes `Pane(2)` and `Singleton<SimpleHelpPane>`, copies text to `m_textBuffer` at `+0xf8`, measures/clamps/attaches the popup, schedules the timer, and seeds opacity. Singleton publication is implicit base construction. |
| `~SimpleHelpPane` | [UID:00048F][0x004c7290-0x004c7307.SimpleHelpPaneDestructor](by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md) | Position `20`; authored body only deletes the copied wide array. Reverse base destruction implicitly clears the singleton and tears down Pane. |
| `OnPaintFrame` | [UID:00048G][0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame](by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md) | Position `30`; draws bordered popup and copied text lines; current `89/91` child evidence uses bounds at `+0x44`, copied text at `+0xf8`, local cursor origin `(5, GetTextLineHeight()+5)`, CR/LF/tab-only delimiters, and a final trailing draw. |
| `OnTimer` | [UID:00048H][0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown](by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md) | TimerHandler-facet callback at complete-object `+0xa4`; `retn 0Ch` supplies three unused arguments, the body closes the pane, and it returns false. Stable `OnMouseDown` slug is historical. |
| `HandlePointerOrMouseEvent` | [UID:00048I][0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent](by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md) | EventHandler-facet override at complete-object `+0xa0`; cursor move or either button-down schedules timer id 0 at zero delay with zero payload, button-down returns handled, and cursor move/other pointer types return unhandled. No timer removal occurs; stable `OnTimerEvent` slug is historical. |
| `HandleKeyOrTextEvent` | [UID:00048J][0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress](by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md) | EventHandler key/text-family override at secondary slot `+8`; closes without reading the Event payload and returns false. Stable `OnKeyPress` slug is historical. |
| `ScalarDeletingDestructor` | [UID:0003YZ][0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor](by-memory/0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor.md) | Non-emitting compiler scalar deleting destructor wrapper; reproduces ordinary/base semantics, interprets deleting flags, conditionally frees object storage, guards size `0xfc`, and keeps formal C++ blank. |

## Evidence Notes

- IDA confirms all listed function starts and sizes.
- The primary vtable at `0x0061abe4` routes deletion to UID0003YZ; EventHandler/TimerHandler views at `0x0061ac30/0x0061ac60` route through `this -= 0xa0/-0xa4` adjustors. These scalar/adjustor/vtable artifacts are generated by the virtual destructor declaration and must not be handwritten.
- Exact source order is constructor `10`, ordinary destructor `20`, paint `30`, timer `40`, pointer/mouse `50`, and key/text `60`. The class block ends before `[[CHILDREN]]`, so child definitions remain the sole method-body emitters.
- IDA xrefs to the constructor span inventory, status, self-look, user-look, menu, and other UI callers, supporting a reusable tooltip role.
- Legacy generated event methods rendered through `BulletinSession` owner-offset types. Current table/RTTI evidence resolves EventHandler at complete-object `+0xa0` and TimerHandler at `+0xa4`; the generated owner/type labels are historical pollution, not accepted source.
- 2026-06-27 B007 split implementation turns [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) into a non-emitting parent index; exact method children [UID:00048E][0x004c6f90-0x004c7287.SimpleHelpPaneConstructor](by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md)-[UID:00048J][0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress](by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md) now carry owner/emitter [UID:0000D6] and source-shaped formal C++ bodies.
- The constructor child preserves the broad direct constructor xrefs, implicit Singleton-base publication, popup sizing/clamping, timer scheduling, and copied text buffer ownership through field `+0xf8` (`m_textBuffer` / historical alias `m_copiedTextBuffer`).
- The corrected child pages separate three interfaces: UID00048H is TimerHandler `OnTimer(int,int,int)`; UID00048I is EventHandler `HandlePointerOrMouseEvent(Event *)`; UID00048J is EventHandler `HandleKeyOrTextEvent(Event *)`. Their positions are `40/50/60`, and only exact children emit bodies.
- UID00048I and constructor paths call accepted `TimerHandler::ScheduleTimer`, not cancellation/removal. `0x005975e0` queues timer id/delay/payload, while owner-wide removal is separate `0x00597600`; historical `CancelTimer` prose is superseded.
- Event type byte is unsigned `m_type` at `+0x04`; accepted pointer-family values are cursor move `0`, left button down `1`, and right button down `4`. Shared Event pointer payload order is y at `+0x08`, x at `+0x0c`.
- 2026-05-26 IDA MCP storage check confirms [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) as a 4-byte `.data` singleton with 23 data references.
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) is attached to [UID:0000JU][HelpPanes](by-file/HelpPanes.md) and documents exact `SimpleHelpPane` constructor, ordinary destructor, paint, mouse, timer, and key handlers, plus the adjacent `SimpleHelpPane2` constructor/teardown/event cluster.
- [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md) is attached to [UID:0000JU][HelpPanes](by-file/HelpPanes.md) and records the exact `0x0069ae00` singleton storage, initialized bytes, constructor publish/fallback clear, ordinary teardown clear, support-helper clear, scalar deleting destructor clear, close-helper read, and broad feature consumers.
- [UID:00025G][0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData](by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md) places the `SimpleHelpPane` vtable in the same help/item-help read-only data span as the rest of the HelpPanes family.
- 2026-07-04 B013 UID00048G MCP session `73c77998` reconfirmed `SimpleHelpPane::OnPaintFrame` at exact range `0x004c7310-0x004c743e`, size `0x12e` / 302 bytes, with `0x004c743e` not a function, successor `0x004c7440`, two trailing `0xcc` padding bytes, vtable xref `0x0061ac28`, and no code callers. Its corrected formal C++ replaces the older NUL-delimiter/CRLF-coalescing draft with the observed CR/LF/tab delimiter loop and post-loop tail draw.
- 2026-06-14 live IDA MCP refresh reconfirmed the `SimpleHelpPane` constructor at `0x004c6f90` as size `0x2f7`, ordinary destructor `0x004c7290` as size `0x77`, paint `0x004c7310` as size `0x12e`, historical-name target `0x004c7450` as size `0x41`, and the adjacent `SimpleHelpPane2` constructor/destructor/event bodies in the same cluster. Current interface reanalysis classifies `0x004c7450` as EventHandler pointer/mouse, not TimerHandler. `analyze_function 0x004c6f90` reports 18 direct constructor xrefs across inventory, self-look/user-look, menu, status, and related UI flows, while `trace_data_flow 0x0069ae00` reconfirms singleton publish/clear sites and external readers. `entity_query` over `0x0061abe0-0x0061ad00` reconfirms the `SimpleHelpPane` and `SimpleHelpPane2` vtable triplets before the `WillBeChangedItemPane` successor.

## 2026-06-17 Scalar Destructor Wrapper Split

- B003 split [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) and assigned the exact `0x004ce560-0x004ce618` wrapper to [UID:0003YZ][0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor](by-memory/0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor.md) at `87/92`, owner/emitter [UID:0000D6].
- Source-facing name is `virtual SimpleHelpPane::~SimpleHelpPane()`. The scalar wrapper and adjustor thunks are compiler ABI output and formal wrapper C++ stays blank.
- The wrapper validates `g_pSimpleHelpPane` (`dword_69AE00`) cleanup, copied text buffer field direction `m_textBuffer` / `m_copiedTextBuffer` at `+0xf8`, primary vtable slot `0x0061abe4`, and secondary/tertiary views at `0x0061ac30/0x0061ac60`.

## Parent And Score Rationale

| Topic | Rationale |
| --- | --- |
| Source parent | [UID:0000JU][HelpPanes](by-file/HelpPanes.md) is now `90/86`, has the `NexusTK/ui/controls/` path, and owns the contiguous help/tooltip pane source family. |
| Exact method evidence | [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) is now a non-emitting split index, while exact child pages [UID:00048E][0x004c6f90-0x004c7287.SimpleHelpPaneConstructor](by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md)-[UID:00048J][0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress](by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md) carry method-level source evidence and formal C++. |
| Singleton evidence | [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md) and [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) document the active-pane lifecycle and feature-reader set. |
| Remaining blockers | Event interface/type names, timer schedule/remove semantics, inheritance, EBO layout, complete size, declaration, and source order are resolved. Only original private/access/header spellings remain a confidence cap below 95; they do not block the complete class draft at `92/94`. |

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md)
- [UID:00048E][0x004c6f90-0x004c7287.SimpleHelpPaneConstructor](by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md)
- [UID:00048F][0x004c7290-0x004c7307.SimpleHelpPaneDestructor](by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md)
- [UID:00048G][0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame](by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md)
- [UID:00048H][0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown](by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md)
- [UID:00048I][0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent](by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md)
- [UID:00048J][0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress](by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md)
- [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md)
- [UID:00025G][0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData](by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md)
- [UID:000063][HelpPane](by-class/HelpPane.md)
- [UID:0003YZ][0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor](by-memory/0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor.md)

## Changes

- 2026-07-14 B002 UID00048F source-quality callback:
  - Raised the class to `92/94`, set position `10`, and replaced the no-class marker with the complete `Pane` plus `Singleton<SimpleHelpPane>` declaration followed by the post-class `[[CHILDREN]]` insertion point.
  - Recorded RTTI PMD `+0xf8`, EBO overlap with `wchar_t *m_textBuffer`, exact size `0xfc`, exact method order `10/20/30/40/50/60`, implicit singleton construction/destruction, Pane-owned EventHandler/TimerHandler bases, and compiler exclusion of scalar wrappers, adjustors, vptr writes, deleting flags, storage free, and size guards.
  - Historicalized the prior B004 no-standalone class marker and B007/B003 explicit singleton-lifecycle wording as superseded source-shape policy while preserving their split, range, method, vtable, and provenance evidence.

- 2026-07-14 B002 UID00048I implementation callback:
  - Preserved `86/88`, [UID:0000JU][HelpPanes](by-file/HelpPanes.md) owner/emitter routing, and the no-standalone marker plus `[[CHILDREN]]` formal block.
  - Corrected UID00048H/I/J inventory to TimerHandler `OnTimer`, EventHandler pointer/mouse, and EventHandler key/text roles; recorded `+0xa4/+0xa0` base offsets, positions `40/50/60`, schedule-versus-remove behavior, Event constants/type/payload order, direct child-only emission, and historicalized stable slugs without duplicating child source.

- 2026-07-04 B013 [UID:00048G][0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame](by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md) source-quality callback:
  - Updated the method row and evidence notes to the accepted `89/91` paint-child state.
  - Preserved [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md) as the owner/emitter route through [UID:0000JU][HelpPanes](by-file/HelpPanes.md), while recording the vtable-only reachability, exact range/padding, field offsets, helper-role inference caps, CR/LF/tab-only line splitting, and final trailing draw.
  - Historicalized the prior NUL-delimiter and CRLF-coalescing paint draft as stale generated/source-shape inference.

- 2026-06-27 B007 [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) split implementation:
  - Before: completion/confidence were `85/86`, and this class page still referenced the aggregate range rather than exact method children.
  - After: completion/confidence are `86/88`; exact children [UID:00048E][0x004c6f90-0x004c7287.SimpleHelpPaneConstructor](by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md)-[UID:00048J][0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress](by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md) carry method-level formal C++ under owner/emitter [UID:0000D6].
  - Evidence: accepted B007 source-quality report and validator-applied child pages preserve constructor xrefs, copied text buffer field `+0xf8`, timer cancel behavior, close handlers, singleton lifecycle, and parent no-code split-index policy.

- 2026-06-30 B004 HelpPanes empty-emitter first batch:
  - Added the accepted no-standalone class marker plus `[[CHILDREN]]` insertion point to the formal block.
  - Kept [UID:00048E][0x004c6f90-0x004c7287.SimpleHelpPaneConstructor](by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md)-[UID:00048J][0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress](by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md) as the exact source-body emitters and prevented duplicate generation from this class index.

- 2026-06-14 A001 Goal 2 low-confidence refresh:
  - Before: `84/82`, with the direct parent already improved to `90/86` but this class page still carrying stale parent score text and older code-gate wording.
  - After: `85/86`, preserving [UID:0000JU][HelpPanes](by-file/HelpPanes.md) owner/emitter routing and blank final C++ under the active `90/90+` gate.
  - Evidence: live IDA MCP `b001_0003gy` reconfirmed the exact constructor/destructor/paint/timer body sizes, broad constructor xrefs, singleton publish/clear/read data-flow sites, and `SimpleHelpPane`/`SimpleHelpPane2` vtable triplets inside the Help/ItemHelp read-only-data island.
- 2026-06-17 B003 destructor-wrapper split sync:
  - Added exact scalar wrapper child [UID:0003YZ][0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor](by-memory/0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor.md), preserved blank formal C++ policy, and recorded singleton/text-buffer/vtable naming evidence.

- 2026-06-06 A008:
  - Before: confidence was `78` and `AUTOGEN_PARENT_UID` was blank even though the HelpPanes parent, method cluster, singleton global, and singleton storage child all passed the attachment gate.
  - After: changed confidence to `82`, attached the class to [UID:0000JU][HelpPanes](by-file/HelpPanes.md), and added parent/score rationale while keeping completion at `84`.
  - Evidence: [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) documents exact method boundaries and constructor fanout; [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md) and [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) document singleton lifecycle; [UID:0000JU][HelpPanes](by-file/HelpPanes.md) owns the tooltip/help source family at `90/80`.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The timed simple-help tooltip remained unclassified in autogen coverage despite documented constructor, paint/input/timer, singleton, and destructor-wrapper evidence.
  - After: The class is reconstructable but unassigned because the class confidence score remains below the 80/80 parent-attach gate.
  - Evidence: Live IDA MCP lookup confirms constructor/destructor/paint/input/timer starts at `0x004c6f90`, `0x004c7290`, `0x004c7310`, `0x004c7440`, `0x004c7450`, `0x004c74a0`, and scalar deleting destructor `0x004ce560`; existing notes keep generated event-owner type pollution open.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents purpose, ownership, main range, constructor/destructor/paint/input/timer/destructor-wrapper methods, singleton storage, and caller fanout; confidence remains limited by generated event-owner type pollution.
