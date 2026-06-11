*** UID:0000EF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TargetOptionEditControlPane

## Status

- Confidence: strong for behavior and ownership by `TargetOptionDialog`.
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

## Evidence

- Live IDA confirms the constructor's only ordinary code caller is `TargetOptionDialog::TargetOptionDialog` at `0x005423dc`.
- The paint, fixed hook, mouse handler, and hit-test methods are vtable-only methods referenced from TargetOption vtable cells at `0x00618330`, `0x0061835c`, `0x00618358`, and `0x0061834c`.
- The constructor stores the dialog-supplied mode argument and two initial selection bytes; paint and mouse handling use those bytes consistently at the two option-button positions.
- Paint uses the `On` style entries, shared draw-state helpers, the shared draw callback slot, labels `ARROW` or `SHIFT+ARROW`, `USER`, and `MONSTER`, and button rectangles covering x ranges `110-130` and `200-220`.
- Mouse handling ignores non-click event kind values, toggles only the hit option, and signals the inherited invalidation virtual after processing.
- Final C++ is intentionally blank because the class remains below the 95/95 reconstruction-code threshold.

## Cross References

- [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- [UID:0000EE][TargetOptionDialog](by-class/TargetOptionDialog.md)
- [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md)

## Changes

- 2026-06-05 A004 live refresh:
  - Before: the page still carried recovered-source provenance and only summarized the local methods.
  - After: raised from `82/86` to `84/88`, kept parent [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md), removed generated-source provenance, and kept final C++ blank.
  - Evidence: live IDA confirms exact local method sizes, vtable-only virtual reachability, constructor caller, paint label/button layout, mouse toggle and hit-test behavior, destructor wrapper/adjustor thunks, and broad fan-in for the physically shared font setter.
