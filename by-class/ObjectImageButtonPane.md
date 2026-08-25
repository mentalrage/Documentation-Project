*** UID:00009N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ObjectImageButtonPane : public ObjectImageControlPane
{
public:
    ObjectImageButtonPane(const ObjectStatusBlob *objectStatus,
                          const RectBounds *bounds);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnPaint();

    void SetButtonHighlight(bool highlighted);
    bool IsButtonHighlighted() const;

protected:
    virtual unsigned char HitTestPart(int, int)
    {
        return 11;
    }

private:
    bool m_buttonHighlight;
};

typedef char ObjectImageButtonPaneSizeMustBe336[
    sizeof(ObjectImageButtonPane) == 0x150 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ObjectImageButtonPane

## 2026-08-18 Permanent Fold And Vtable Children

- The five authored methods remain on [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md); existing UID0003M9/UID0003MA pages retain button destructor compiler glue.
- [UID:00055Y][0x004242f0-0x004242f5.SharedControlPaneHitTestPartReturn11](by-memory/0x004242f0-0x004242f5.SharedControlPaneHitTestPartReturn11.md) is a physical compiler-fold index only. This class's formal H owns the non-const inline virtual override.
- [UID:00055Z][0x0061f6c0-0x0061f808.ObjectImageControlPaneVtableBand](by-memory/0x0061f6c0-0x0061f808.ObjectImageControlPaneVtableBand.md) records the button primary/EventHandler/TimerHandler tables and exact authored/compiler slots.
- No folded body or vtable array is hand-emitted in CPP.

## Status

- Confidence: strong for class role, object-image source-family placement, inherited `ObjectStatusBlob` descriptor storage, exact source-bearing core split, current getter/setter/highlight field evidence, direct method-cluster owner route, and compiler-generated destructor-glue disposition.
- Likely source file: [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), or an immediately adjacent `ui/controls/ObjectImageButtonPane.cpp` only if later source-file evidence proves a split. Do not route this class to `SpecializedButtonPanes.cpp` from the destructor evidence.
- Address/range evidence: [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md), plus generated destructor-glue pages [0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md) and [0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md).
- Parent attachment: enabled with this class at current `94/94` and the owning file page [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) at current `93/93`. The source-bearing method cluster [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md) uses this class as direct `CANONICAL_OWNER`/`EMITTER_UIDS` and reaches generated source through this class-to-file route.

## Class Purpose

`ObjectImageButtonPane` is a button pane that renders an object or character image centered in its bounds. It inherits the base [UID:00009O][ObjectImageControlPane](by-class/ObjectImageControlPane.md) `ObjectStatusBlob m_objectStatus` snapshot, then adds inline hit-test part reporting, keyboard activation, visual highlight state, and compiler-generated scalar deleting destruction.

## Layout Notes

| Offset | Source-facing field direction | Evidence |
| --- | --- | --- |
| `+0x108..+0x14b` | inherited `ObjectStatusBlob m_objectStatus` | Base [UID:00009O][ObjectImageControlPane](by-class/ObjectImageControlPane.md) copies the 68-byte descriptor here; button paint passes `this+0x108` to the image bounds/draw helpers. |
| `+0x14c` | `bool m_buttonHighlight` / `m_highlighted` | Constructor clears the byte at `0x00520861`, paint tests it at `0x00520930`, setter `0x00520a80` writes it, and getter `0x00520a90` returns it. HeadSelectDialog toggles the setter for selected buttons. |

The constructor also writes inherited/control-state bytes at `+0xff` and `+0x102`; keep those as inherited activation/visual state until the broader control-manager/key-event declarations are final.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `unsigned char HitTestPart(int, int)` | `0x004242f0-0x004242f4` | Protected non-const inline virtual override that returns part code `11`; the formal H owns the source contract and the one physical body is compiler-folded across ten vtables. |
| `ObjectImageButtonPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)` | `0x00520820-0x0052086e` | Forwards the descriptor and bounds to `ObjectImageControlPane`, installs button vtable state, and clears overlay/highlight state. |
| `bool HandleKeyOrTextEvent(Event *event)` | `0x00520870-0x0052090c` | Accepts key-down Space/Return, flashes selection state `11` then `10` for 133 ms, and dispatches command `11` to the parent dialog. |
| `OnPaint` | `0x00520910-0x00520a78` | Centers and renders the object/character image in bounds. |
| `SetButtonHighlight` | `0x00520a80-0x00520a8f` | Stores the supplied byte at `+0x14c` and returns `void`. The assigned byte is incidentally left in `AL` at machine level; that register state is not a C++ return value. |
| `IsButtonHighlighted` | `0x00520a90-0x00520a96` | Retained getter for the same `+0x14c` highlight byte; current MCP session `1f24c222` proves this is source-bearing code, not padding. |
| Adjustor thunks | `0x00520ae7-0x00520afd` | Compiler-generated this-adjustors documented in [0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md); vtable cells `0x0061f7cc`/`0x0061f7fc`, subtract `0xa0`/`0xa4`, and tail-jump to `0x00520c60`. |
| `ScalarDeletingDestructor` | `0x00520c60-0x00520c9b`, size `0x3b` | Compiler-generated wrapper documented in [0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md). It calls inherited pane/control teardown `0x00544580`, checks `flags & 1` / `flags & 4`, frees through `0x004f4ac0(this)` or `0x0041b6a0(this, 0x150)`, returns `this`, and should not emit C++ from the by-memory wrapper. |

## Evidence Notes

- [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md) documents the contiguous source-bearing constructor, key handler, paint method, highlight setter, retained highlight getter, corrected post-range padding boundary, HeadSelectDialog callers, vtable support, direct class owner/emitter route, and formal first-draft C++.
- The destructor adjustor thunks and scalar deleting destructor are intentionally split into exact `RECONSTRUCTABLE:FALSE` compiler-output pages because they are physically interleaved with [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) and should rebuild from the class destructor/vtable layout rather than handwritten source.
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) documents the object-image control source family and why this button subclass should live adjacent to the reusable preview control instead of the generic specialized-button bucket.
- B002 2026-06-19 local PE audit confirms the button scalar wrapper uses complete-object size `0x150`, while the plain [UID:00009O][ObjectImageControlPane](by-class/ObjectImageControlPane.md) sibling wrapper at `0x00520ca0-0x00520cdb` uses `0x14c`. The four-byte growth matches the button subclass extension, including the observed highlight/overlay state byte at `+0x14c` plus alignment.
- Object-image button vtable route: `0x0061f760 -> 0x0064c0b0` RTTI/COL pointer, primary table `0x0061f764` with destructor slot to `0x00520c60`, paint slot `0x0061f7a8 -> 0x00520910`, non-const `HitTestPart` slot `0x0061f7c4 -> 0x004242f0`, secondary destructor slot `0x0061f7cc -> 0x00520ae7`, and tertiary destructor slot `0x0061f7fc -> 0x00520af2`.
- Constructor stores at `0x00520837`, `0x00520843`, and `0x0052084d` install vtable heads `0x0061f764`, `0x0061f7cc`, and `0x0061f7fc`, tying the generated destructor glue to this class rather than to the surrounding mixed menu-dialog thunk island.
- IDA MCP reports one direct constructor xref from `0x00551479`.
- IDA MCP confirms the destructor/thunks are non-contiguous; intervening functions in the `0x00520afd-0x00520c5a` neighborhood belong to `ObjectImageControlPane`, `ClientItemMenuItemList`, or other classes.
- 2026-05-24 IDA MCP confirms the constructor directly calls `ObjectImageControlPane::ObjectImageControlPane` at `0x00520830`, then installs three `ObjectImageButtonPane` vtable pointers and clears state bytes at `+0x102`, `+0xff`, and `+0x14c`.
- 2026-05-24 IDA MCP decompiles the deleting destructor as `sub_544580(this)` plus conditional `sub_4F4AC0(this)`. The generated `TextButtonExControlPane`/`Pane` base label is owner-name pollution.
- `SetButtonHighlight` is called by [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md) paths at `0x0055149a`, `0x0055209a`, and `0x005520c3`.
- [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md) creates paged head-selection buttons with this class and toggles highlight state as the selected head changes.
- B008 2026-06-19 base-control source-quality reanalysis replaces the old unresolved image-descriptor wording with the shared [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md) direction. The button constructor forwards the same `const ObjectStatusBlob *objectStatus, const RectBounds *bounds` pair to the base constructor, inherits the 68-byte blob at base offset `+0x108..+0x14b`, and places its own highlight/overlay byte at `+0x14c`, immediately after the base `0x14c` size.
- B002 2026-07-02 current MCP session `1f24c222` refreshed the source-bearing core: `lookup_funcs` reports `0x00520a90` as real function `sub_520A90` size `0x7`; decompilation returns `this[332]`; disassembly is `mov al, [ecx+14Ch]; retn`; `xrefs_to` reports no inbound xrefs, so the function is best treated as a retained/unreferenced getter rather than padding. The corrected core range is `0x00520820-0x00520a97`.

## Attachment and Reconstruction State

- Attached to [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) after the class page was refreshed from the reviewed memory page and the object-image control file owner.
- Keep [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) as a historical cross-reference only; current by-* evidence favors the object-image source family.
- The destructor wrapper pages are no-code compiler glue. Class-level source may rely on the implicit/default virtual destructor, or list an empty/default destructor declaration if the final local header style explicitly declares pane subclass destructors.
- The class formal CPP is the accepted `[[CHILDREN]]` route, with the exact five authored method definitions supplied by [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md). The formal H is complete and authoritative: constructor, virtual `HandleKeyOrTextEvent(Event *)`, virtual `OnPaint`, highlight setter/getter, protected inline non-const `HitTestPart(int,int)`, private highlight byte, and `0x150` size guard. No declaration is withheld; inferred original spellings only retain the existing confidence cap.

## Cross-References

- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:00009O][ObjectImageControlPane](by-class/ObjectImageControlPane.md)
- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md)
- [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md)
- [0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md)
- [0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md)

## Changes

- 2026-08-23 B010 Gate 2A void-setter prose repair: corrected the active `SetButtonHighlight(bool)` method description to the accepted `void` source contract. The earlier source-level claim that the setter returned the new value is superseded; the assigned byte being left in `AL` is incidental machine state, not a C++ return value. Formal CPP/H, layout, behavior, routes, and scores are unchanged.
- 2026-08-22 B010 Gate 2A contradiction repair: made the complete formal H/current closure authoritative, replaced active `OnKeyPress` with `HandleKeyOrTextEvent(Event *)`, and replaced source-facing `GetPaneTypeCode` wording with the accepted non-const inline `HitTestPart(int,int)` override while preserving the physical folded-body evidence.
- 2026-08-22 B010 Gate 2A repair: reconciled active Status prose with current class `94/94` and owning-file `93/93`; the earlier `87/90` and `88/88` values remain only in their dated callback history below.
- 2026-06-12 Supervisor Goal 2 barrier repair: raised completion/confidence from `82/84` to `85/86` after splitting the old broad memory page into the source-bearing core now documented as [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md) and exact generated destructor-glue pages. The class remains attached to [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) because both now clear the strict `85/85` gate.
- 2026-07-02 B002 UID0001BV implementation callback: raised from `86/88` to `87/90`, updated the source-bearing core to [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md), added the retained `IsButtonHighlighted` getter at `0x00520a90-0x00520a97`, documented `+0x14c` as `m_buttonHighlight` / `m_highlighted`, and recorded that [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md) now routes directly through this class as owner/emitter while still surfacing to [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md).
- 2026-06-20 B002 Rule 26 incorporation: raised from `85/86` to `86/88` after local PE byte/disassembly review resolved destructor-wrapper routing, exact thunk subtracts, vtable cells, sibling size comparison (`0x150` versus `0x14c`), source-family placement under [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), and the no-code policy for [UID:0003M9][0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md)/[UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md).
- 2026-06-21 B008 base-control descriptor sync: score unchanged. Replaced unresolved image-descriptor wording with inherited `ObjectStatusBlob m_objectStatus`, documented constructor forwarding as `ObjectImageButtonPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)`, and kept button C++ blank pending a dedicated button key/paint/highlight source-quality pass.
- 2026-06-06: Raised completion from `78` to `82`, attached the class to [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), replaced generated-source/Wave-derived evidence framing with the reviewed by-memory/by-file basis, and added attachment/reconstruction state. Confidence stays `84` because role, methods, callers, and source-family placement are strong while final field names and source-quality declarations remain open.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed type-code, constructor, key, paint, highlight, thunk, and deleting-destructor functions at `0x004242f0`, `0x00520820`, `0x00520870`, `0x00520910`, `0x00520a80`, `0x00520ae7`, `0x00520af2`, and `0x00520c60`. Left `AUTOGEN_PARENT_UID` blank because this class is still below the 80 completion attachment gate.
- Before: completion/confidence metadata were `0/0` even though the page already captured behavior, method boundaries, non-contiguous destructor support, callers, and source-family placement.
- Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
- Evidence: constructor, activation, painting, highlight, type-code, thunk/destructor, base-owner pollution, and `HeadSelectDialog` usage are documented; remaining gaps are detailed field names and full reconstructed C++.

## 2026-08-18 Accepted Class Closure

- `ObjectImageButtonPane` directly derives from `ObjectImageControlPane`, adds only `bool m_buttonHighlight` at `+0x14c`, and has exact complete-object size `0x150`.
- The formal H declares constructor, virtual `HandleKeyOrTextEvent(Event *)`, virtual `OnPaint`, highlight setter/getter, and the protected inline non-const `HitTestPart(int,int) { return 11; }`. Non-const qualification is required to override the inherited `ControlPane` slot; a `const` overload or receiverless helper is rejected.
- Source children appear in order: constructor, event handler, paint, setter, getter. The shared five-byte physical return-11 body is compiler-folded across ten vtables and remains a non-emitting physical index. Primary/EventHandler/TimerHandler tables are `0x0061f764`, `0x0061f7cc`, and `0x0061f7fc`.
- Destructor adjustors at `0x00520ae7/0x00520af2`, scalar wrapper at `0x00520c60`, vtables, RTTI, and folded inline body are compiler output. The class declaration and implicit virtual destructor regenerate them; no manual helper/destructor source is emitted.
- Completion/confidence `94/94` reflects exact layout, five authored out-of-line methods, inline virtual override, complete source order, resources/callers, compiler split, and generated declaration verification. Original lexical spellings and rebuilt-binary comparison remain the only score caps.
