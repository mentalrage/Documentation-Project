*** UID:0000CQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelectBoxControlPane : public ControlPane
{
public:
    explicit SelectBoxControlPane(const RectBounds *bounds);

    bool IsSelected() const;
    void SetSelected(bool selected);

protected:
    virtual bool OnMouseEvent(const EventRecord *event);
    virtual void OnPaint();

private:
    bool m_selected; // +0x108, object size 0x10c
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SelectBoxControlPane

## Status

- Confidence: strong for behavior, vtable identity, state field, and method boundaries; medium-high for final file grouping.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), with `ChoiceControlPane.cpp` still possible only as a later original-name/source-split refinement.
- Historical generated source candidate: `class_SelectBoxControlPane.cpp`; use only as search context, not as authority.
- Parent-gate status: reconstructable class attached to direct file parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md). Exact source-bearing SelectBox methods route here; shared compiler deleting entry [UID:0002XW][0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md) is an equal consumer relationship, not a directly owned class child.

## Class Purpose

`SelectBoxControlPane` displays a selectable framed box. It constructs a `ControlPane`-derived object, tracks one local selected-state byte, hit-tests mouse events against inherited bounds, invalidates itself when selection changes, and paints a double rectangle indication for selected or non-default inherited visual state.

B002's 2026-06-18 source-quality pass resolves the former host/callback uncertainty: this class does not carry a host-selection pointer, callback member, or selection-group field in the `0x004fccf0-0x004fce7e` method island. Dialog-level group clearing is external NewUserMisc caller behavior through direct `SetSelected(bool)` calls.

## Layout Notes

`SelectBoxControlPane` adds one confirmed class-specific field: `bool m_selected` at `+0x108` (`+264` decimal), within an object size of `0x10c` corroborated by the shared deleting entry's bit-4 size branch. Direct callee analysis proves that branch reaches a one-byte no-op helper, not a vector-element destructor.

Inherited fields and views used by the methods:

| Offset | Role |
| --- | --- |
| `+0x44` | inherited bounds rectangle, used for hit testing, invalidation, background draw, and frame drawing. |
| `+0x103` | inherited `ControlPane` visual-state byte; paint suppresses the frame only when `!m_selected && visualState == 10`. |
| `+0xa0` | `EventHandler` secondary vtable view; the mouse-event method receives this adjusted pointer. |
| `+0xa4` | tertiary inherited/default handler view. |

Resolved source-facing methods from [UID:00019V][0x004fccf0-0x004fce7e.SelectBoxControlPane](by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md) are `SelectBoxControlPane(const RectBounds *bounds)`, `IsSelected() const`, `SetSelected(bool)`, `OnMouseEvent(const EventRecord *)`, and `OnPaint()`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| Shared deleting-destructor glue | `0x0049af11-0x0049af27`, `0x0049b0d0-0x0049b10b` | Compiler adjustors and folded deleting entry consumed by SelectBox and three other classes; not SelectBox-owned source. |
| `SelectBoxControlPane(const RectBounds *bounds)` | `0x004fccf0-0x004fcd67` | Constructs from a bounds pointer, passes control type `8` to `ControlPane::ControlPane`, writes primary/secondary/tertiary vtables, clears `m_selected`, and calls `Pane::SetMode(1)`. |
| `IsSelected() const` | `0x004fcd70-0x004fcd77` | Returns `m_selected` at object offset `+0x108`. |
| `SetSelected(bool)` | `0x004fcd80-0x004fcda4` | Updates `m_selected` and invalidates inherited bounds through vtable slot `+0x20` only when the state changes. |
| `OnMouseEvent(const EventRecord *)` | `0x004fcdb0-0x004fcdf7` | EventHandler secondary-view method; filters type `3`, hit-tests coordinates against inherited bounds, adjusts back to the primary receiver, sets `m_selected`, and invalidates. |
| `OnPaint()` | `0x004fce00-0x004fce7e` | Draws selection frame/double border using inherited bounds and visual state. |

## Evidence Notes

- 2026-06-06 live IDA MCP confirms exact functions at `0x004fccf0` (`0x78`), `0x004fcd70` (`0x7`), `0x004fcd80` (`0x24`), `0x004fcdb0` (`0x48`), `0x004fce00` (`0x7f`), thunk `0x0049af11` (`0xb`), scalar deleting destructor `0x0049b0d0` (`0x3b`), and next owner `0x004fce80` (`UserShapeSelectControlPane`, `0x135`).
- Constructor decompilation calls the base control constructor `0x004949e0`, installs `SelectBoxControlPane` vtable views at `0x0061d4c0`, `0x0061d528`, and `0x0061d558`, clears selected byte `+264`, and enables the pane through `0x005446b0`.
- The selected-state setter has seven direct callers in the new-user miscellaneous dialog path `0x004fc010`, covering shape/option state resets; the constructor and paint/mouse virtuals have no direct code callers because current evidence reaches them through construction/vtable data.
- Vtable xrefs tie `OnPaint` to slot data at `0x0061d504` and the resolved `OnMouseEvent` handler, formerly labeled `OnMouseDown` in older notes, to slot data at `0x0061d52c`; constructor vtable stores are at `0x004fcd2e`, `0x004fcd34`, and `0x004fcd3e`.
- Source grouping is still capped below final-source quality because this exact class island is physically closer to new-user shape dialogs, while the generic behavior and existing [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) file page keep it in the reusable button/choice-control family.
- 2026-06-08 A004 Batch 114 confirmed the constructor/method cluster and observed `0x0049b0d0` performing only base Pane teardown and deletion-mode dispatch. That pass inferred direct SelectBox ownership from the narrow title and Select vtable use. The 2026-07-23 four-class route audit supersedes only that ownership inference: Button, Select, Weather, and Rain primary vtables point to the same class-neutral wrapper, and all four also share its two adjusted entries.
- 2026-06-18 B002 source-quality pass confirmed the primary vtable `0x0061d4c0` at object offset `+0x00`, EventHandler secondary vtable `0x0061d528` at `+0xa0`, and tertiary inherited/default handler vtable `0x0061d558` at `+0xa4`. The EventHandler mouse-event body receives `this+0xa0`, reaches inherited bounds with `(this+0xa0)-0x5c == this+0x44`, and converts back to the primary receiver with `-0xa0` before writing `m_selected`.
- The class-level reconstruction block intentionally places `[[CHILDREN]]` after the declaration so exact by-memory method definitions from [UID:00019V][0x004fccf0-0x004fce7e.SelectBoxControlPane](by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md) emit outside the class body.
- The same B002 pass recorded the negative host/callback finding: the mouse-event body reads no owner dialog pointer, callback table, action id, sibling list, or selection-group field. NewUserMisc callers coordinate groups externally through seven direct setter calls.

## Shared Deleting-Entry Source Relationship

- SelectBox primary slot `0x0061d4c0` points to UID0002XW, while its `+0xa0` and `+0xa4` views at `0x0061d528` and `0x0061d558` point to the UID0002XV adjustors.
- Button, Weather, and Rain have equivalent primary and adjusted routes. The target contains no `m_selected` access, no vptr restore, and no Select-specific member cleanup.
- The one body always tears down Pane, optionally invokes operator delete for deleting-flags bit 1, and uses `0x10c` only on a separate bit-4 call to a one-byte no-op helper.
- Best source shape is the current class declaration without a speculative explicit destructor. An implicit virtual destructor can cause the same compiler-generated deleting entry; a hand-authored `ScalarDeletingDestructor` method or marker comment would be reverse-engineering scaffolding.
- UID0002XW is therefore layout/compiler evidence for this class, not a canonical child owner/emitter route. The physical target filename is retained as a historical link-stability alias.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:00019V][0x004fccf0-0x004fce7e.SelectBoxControlPane](by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md)

## Score Rationale

- Completion is `88` because the page now records exact constructor/accessor/setter/EventHandler mouse-event/paint/destructor boundaries, vtable stores, receiver adjustment, selected-state field and object size, setter fan-in, negative host/callback evidence, source-facing method names, direct file parent, and first-draft declaration C++.
- Confidence is `89` because the method bodies, Select vtable refs, setter callers, `0x10c` layout evidence, and support docs consistently support this class under [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md). UID0002XW is deliberately excluded from direct ownership because four separate class families consume it equally. Confidence stays below final audit because shared Event/GrafPort/Rect helper names and the future `ButtonControlPane.cpp` versus `ChoiceControlPane.cpp` source split remain descriptive.

## Changes

- 2026-07-23 B002 UID0002XW source-quality callback:
  - Score, owner/emitter, formal class declaration, methods, fields, and source-file route unchanged.
  - Replaced stale direct ownership of UID0002XW with equal-consumer/compiler-source-cause wording, corrected the bit-4 vector-delete assumption to the proved one-byte no-op helper, and retained `0x10c` as valid layout corroboration.
  - Preserved the likely implicit destructor source shape; no speculative explicit destructor or ABI wrapper declaration was added.
- 2026-06-18 B002 source-quality execution:
  - Changed from `85/86` to `88/89`.
  - Populated class-level declaration C++ for the resolved constructor/accessor/setter/EventHandler paint shape, with `[[CHILDREN]]` after the declaration so method bodies emit outside the class body.
  - Added `m_selected` at `+0x108`, inherited field/view notes, vtable/receiver adjustment, negative host/callback evidence, and external NewUserMisc group-reset behavior.
  - Updated method names from raw `+264`/`OnMouseDown` wording to source-facing `IsSelected`, `SetSelected`, `OnMouseEvent`, and `OnPaint`.
- 2026-06-08 A004 Batch 114 strict parent-gate update:
  - Changed from `82/84` to `85/86`; kept `AUTOGEN_PARENT_UID:0000HY`.
  - Evidence: live IDA rechecked constructor/accessor/setter/mouse/paint/destructor sizes and behavior, selected byte `+264`, setter fan-in, vtable data ownership, and direct parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) at `86/88`. The historical blank-C++ staging note from this pass is superseded by the 2026-06-18 B002 source-quality execution, which resolved the class declaration and populated first-draft C++ under the active code-entry rule.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The selectable framed-box control remained unclassified in autogen coverage despite documented constructor, mouse, paint, and destructor-thunk evidence.
  - After: The class is reconstructable but unassigned because the class confidence and likely parent completion scores are below the 80/80 parent-attach gate.
  - Evidence: Live IDA MCP lookup confirms modeled starts at `0x004fccf0`, `0x004fcdb0`, `0x004fce00`, and destructor-thunk/deleting-destructor neighborhood starts at `0x0049af11` and `0x0049b100`; existing notes keep final source-file grouping open.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `76`, confidence `78`.
- Evidence: the page has the class purpose, likely file ownership, recovered method table, core by-memory link, and direct IDA/Wave3 caveat for the constructor-xref gap; remaining uncertainty is final source-file grouping.

- 2026-06-06 live IDA parent-readiness pass:
  - Before: the page was reconstructable but unassigned, and it omitted the accessor/setter method split and vtable-store evidence.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, and parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md).
  - Evidence: live IDA MCP rechecked the exact constructor/accessor/setter/mouse/paint/destructor boundaries, constructor vtable stores, vtable data refs, seven new-user caller sites into the selected-state setter, selected byte offset `+264`, and the `0x004fce80` next-owner boundary. The historical blank-C++/95-gate note from this pass is superseded by the 2026-06-18 B002 source-quality execution, which resolved `m_selected`, method names, class-level declaration shape, and first-draft C++ readiness.
