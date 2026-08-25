*** UID:0000EF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TargetOptionEditControlPane : public ControlPane
{
public:
    TargetOptionEditControlPane(int optionMode,
                                unsigned char userTargetEnabled,
                                unsigned char monsterTargetEnabled,
                                const RectBounds *bounds);
    virtual ~TargetOptionEditControlPane();

    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual char HitTestPart(int mouseY, int mouseX);

    unsigned char GetUserTargetEnabled() const
    {
        return m_userTargetEnabled;
    }

    unsigned char GetMonsterTargetEnabled() const
    {
        return m_monsterTargetEnabled;
    }

private:
    int m_targetOptionMode;
    unsigned char m_userTargetEnabled;
    unsigned char m_monsterTargetEnabled;
};
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TargetOptionEditControlPane

## Status

- Confidence: very strong for declaration, `0x110` layout, field/config mapping, vtable reachability, and ownership by `TargetOptionDialog`.
- Likely source file: [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- Main address doc: [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md)

## Functionality

`TargetOptionEditControlPane` is the custom row control used by `TargetOptionDialog`. It draws the current targeting mode caption plus the `USER` and `MONSTER` choices, toggles the two stored selection bytes on mouse clicks, exposes the same two-button hit test, and uses a shared font-id setter during painting.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x004993b0-0x00499401` | Calls the `ControlPane` base constructor with kind `8`, stores the option-mode argument and two selection bytes, and installs the primary/secondary/tertiary vtables. |
| non-deleting destructor | `0x00499410-0x0049942e` | Restores the same three vtables, then tail-jumps to shared pane teardown. |
| paint | `0x00499430-0x00499653` | Draws `ARROW` or `SHIFT+ARROW`, labels `USER` and `MONSTER`, and renders the two selected/unselected button states. |
| fixed return hook | `0x00499660-0x00499664` | Vtable-only hook returning zero through `retn 4`. |
| mouse handler | `0x00499670-0x0049976c` | Handles click events, hit-tests the two button rectangles, toggles the matching selection byte, and invalidates the inherited control view. |
| hit test | `0x00499770-0x0049980c` | Returns `0`, `1`, or `-1` for the same two target-option rectangles. |
| scalar deleting destructor | `0x0049b740-0x0049b794` | Restores vtables, runs shared pane teardown, and frees the object on the normal deleting path; adjustor thunks at `0x0049b045` and `0x0049b050` jump here. |
| shared font setter | `0x004b9640-0x004b9657` | Writes the font id field only for values `0` and `1`; called by this paint method but shared with other UI text controls. |

## Layout And Source Contract

- Accepted object size is `0x110`; [UID:000038][ControlPane](by-class/ControlPane.md) occupies `0x108` bytes.
- `int m_targetOptionMode` is at `+0x108`, `unsigned char m_userTargetEnabled` is at `+0x10c`, and `unsigned char m_monsterTargetEnabled` is at `+0x10d`. Bytes `+0x10e/+0x10f` are implicit class tail padding, not a source reserve field.
- Mode `0` renders `ARROW`; mode `1` renders `SHIFT+ARROW`. Inline const accessors preserve direct byte loads for `TargetOptionDialog::SaveTargetOptions` without public fields, friendship assumptions, or cross-class offset arithmetic.
- The accepted declarations cover constructor/destructor, paint, pointer/mouse input, key/text fixed-return hook, and `char` hit test. The AL return with values `0`, `1`, and `-1` supports the signed one-byte `HitTestPart` result.
- The class declaration is complete and source-bearing even though [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md) remains a separate unsplit inventory for the method bodies. `[[CHILDREN]]` preserves that distinction.

## Evidence

- Live IDA confirms the constructor's only ordinary code caller is `TargetOptionDialog::TargetOptionDialog` at `0x005423dc`.
- The paint, fixed hook, mouse handler, and hit-test methods are vtable-only methods referenced from TargetOption vtable cells at `0x00618330`, `0x0061835c`, `0x00618358`, and `0x0061834c`.
- The constructor stores the dialog-supplied mode argument and two initial selection bytes; paint and mouse handling use those bytes consistently at the two option-button positions.
- Paint uses the `On` style entries, shared draw-state helpers, the shared draw callback slot, labels `ARROW` or `SHIFT+ARROW`, `USER`, and `MONSTER`, and button rectangles covering x ranges `110-130` and `200-220`.
- Mouse handling ignores non-click event kind values, toggles only the hit option, and signals the inherited invalidation virtual after processing.
- 2026-06-16 B002 source-quality reanalysis: the dialog constructs two instances, mode `0` for `ARROW` and mode `1` for `SHIFT+ARROW`. Each instance stores `m_targetOptionMode` at `+0x108`, `m_userTargetEnabled` at byte `+0x10c`, and `m_monsterTargetEnabled` at byte `+0x10d`.
- The fixed false-return body at `0x00499660` is a real vtable slot implementation, but the inherited slot name is not recovered. The adjustor thunks at `0x0049b045` and `0x0049b050` are compiler-generated ABI support and should not be emitted as handwritten source.
- Paint uses verified UTF-16 labels `ARROW`, `SHIFT+ARROW`, `USER`, and `MONSTER`, style key `ON`, and two local rectangles `(110,0)-(130,20)` and `(200,0)-(220,20)`. Mouse handling accepts only event kind byte `1`, tests those same rectangles, toggles the matching byte, and invalidates the inherited control view.
- The accepted class declaration now closes the former blank-class blocker. Exact bodies remain governed by UID00011K's separate method inventory; compiler adjustors/scalar wrapper/vtable data remain excluded.

## Source-Quality Reanalysis

`TargetOptionEditControlPane` is a row control in `TargetOptionDialog.cpp`. The dialog constructs two instances: mode `0` for `ARROW` and mode `1` for `SHIFT+ARROW`. Each instance stores `m_targetOptionMode` at `+0x108`, `m_userTargetEnabled` at byte `+0x10c`, and `m_monsterTargetEnabled` at byte `+0x10d`.

The class owns the constructor, non-deleting destructor helper, paint method, mouse-event handler, two-button hit-test helper, and scalar deleting destructor ABI wrapper. The fixed false-return body at `0x00499660` is a real vtable slot implementation, but the inherited slot name is not recovered. The adjustor thunks at `0x0049b045` and `0x0049b050` are compiler-generated ABI support and should not be emitted as handwritten source.

Paint uses verified UTF-16 labels `ARROW`, `SHIFT+ARROW`, `USER`, and `MONSTER`, style key `ON`, and two local rectangles `(110,0)-(130,20)` and `(200,0)-(220,20)`. Mouse handling accepts only event kind byte `1`, tests those same rectangles, toggles the matching byte, and invalidates the inherited control view.

The complete class declaration is emitted at position `0`. Historical blanket no-C++ wording applied to the unresolved method aggregate, not to this now-source-safe declaration; it is superseded for class/layout/accessor emission while preserved for the separate body inventory.

## Score Rationale

Completion is `90` because the page now emits the complete declaration and records exact size, field offsets/types, implicit tail padding, inline accessors, method/vtable contract, config-row semantics, constructor caller, compiler exclusions, and deterministic source position. Confidence is `92`; original private/header spelling and the separate unsplit method-body inventory remain caps.

## Cross References

- [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- [UID:0000EE][TargetOptionDialog](by-class/TargetOptionDialog.md)
- [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md)

## Changes

- 2026-07-14 B002 UID0001E2 implementation callback:
  - Raised `86/90` to `90/92`, set source position `0`, and installed the accepted complete `0x110` class declaration.
  - Added exact base/field/tail-padding/accessor/method contract and clarified that UID00011K remains the separate method-body inventory. Historical blank-class wording below is evidence-time/superseded for declaration emission, not deleted provenance.

- 2026-06-05 A004 live refresh:
  - Before: the page still carried recovered-source provenance and only summarized the local methods.
  - After: raised from `82/86` to `84/88`, kept parent [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md), removed generated-source provenance, and kept final C++ blank.
  - Evidence: live IDA confirms exact local method sizes, vtable-only virtual reachability, constructor caller, paint label/button layout, mouse toggle and hit-test behavior, destructor wrapper/adjustor thunks, and broad fan-in for the physically shared font setter.
- 2026-06-16 B002 source-quality audit:
  - Raised from `84/88` to `86/90` with no owner/emitter change.
  - Evidence: rechecked target field bytes `+0x108/+0x10c/+0x10d`, config rows, raw UTF-16 labels, hit rectangles, fixed false-return slot, destructor/scalar-wrapper/adjustor ownership, shared font-setter fan-in, and `TargetOptionDialog.cpp` source placement. C++ remains blank pending source-grade inherited virtual/event/helper/resource names.
