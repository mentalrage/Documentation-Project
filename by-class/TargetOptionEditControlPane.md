*** UID:0000EF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TargetOptionEditControlPane

## Status

- Confidence: strong for behavior and ownership by `TargetOptionDialog`.
- Likely source file: [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- Main address doc: [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md)
- Current recovered file: `source-3/simroot_v2/class_TargetOptionEditControlPane.cpp`

## Functionality

`TargetOptionEditControlPane` is the custom row control used by `TargetOptionDialog`. It draws two selectable target-option choices, accepts mouse selection, exposes hit testing, and supports font selection for rendering.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x004993b0-0x00499401` | Initializes the control state and vtables. |
| paint | `0x00499430-0x00499653` | Draws the target-option row and choice buttons. |
| selectable/mouse/hit-test | `0x00499660`, `0x00499670-0x0049976c`, `0x00499770-0x0049980c` | Exposes selectability, handles mouse input, and returns clicked choice. |
| scalar deleting destructor | `0x0049b740-0x0049b794` | Deleting destructor wrapper in the control destructor island. |
| `SetFontId` | `0x004b9640` | Sets text font id; physically outside the local control range. |

## Evidence

IDA confirms the only constructor xref observed in this pass is from `TargetOptionDialog::TargetOptionDialog` at `0x005423dc`.

## Cross References

- [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- [UID:0000EE][TargetOptionDialog](by-class/TargetOptionDialog.md)
- [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `86`.
- Evidence: the page documents control role, owner dialog, constructor/paint/mouse/hit-test/destructor/font setter ranges, and constructor xref from `TargetOptionDialog`; remaining completion gap is source-ready C++ and field naming.
