*** UID:00009K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NumberInputDialog

## Status

- Confidence: strong for recovered behavior and method boundaries.
- Likely source: [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- Current recovered source: `source-3/simroot_v2/class_NumberInputDialog.cpp`
- Memory: [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)

## Responsibility

`NumberInputDialog` is a `DialogPane`-derived modal prompt for integer entry. It owns the prompt label, edit field, OK/cancel buttons, range validation, out-of-range alert, and callback dispatch.

## Layout Evidence

IDA offsets in `OnConfirm` and destructor support the following tail fields after the `DialogPane` base:

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x26c` | `m_confirmCallback` | Constructor stores arg `a3`; `OnConfirm` calls vtable slot `+12` with the parsed integer. Destructor deletes this object if present. |
| `+0x270` | `m_cancelCallback` | Constructor stores arg `a4`; cancel action calls vtable slot `+12` with no parsed value. |
| `+0x274` | `m_minValue` | `OnConfirm` rejects values below this field. |
| `+0x278` | `m_maxValue` | `OnConfirm` rejects values above this field. |
| child `1` | OK button | Set as default action / OK button index. |
| child `2` | cancel button | Set as cancel action / cancel button index. |
| child `3` | prompt label | Constructed from caller-provided prompt text. |
| child `4` | edit control | Focus control; text is copied and parsed as an integer. |

## Method Families

| Range | Method | Summary |
| --- | --- | --- |
| [UID:0001CV][0x00530640-0x00530b00.NumberInputDialogConstructor](by-memory/0x00530640-0x00530b00.NumberInputDialogConstructor.md) | constructor | Builds either EPF or EPD layout, adds controls, sets focus/default/cancel controls, bounds, position, and slide-open state. |
| [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md) | destructor body | Real bytes but not an IDA function object; resets vtables, deletes callback target, and jumps to base cleanup. |
| [UID:0001CY][0x00530b40-0x00530c78.NumberInputDialogActionHandler](by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md) | action handler | Confirms, validates, reports parsed value, closes, or cancels and calls cancel callback. |
| [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md) | destructor adjustor thunks | Two real secondary-vtable thunks for `this - 160` and `this - 164`; excluded through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md) | scalar deleting destructor | Same cleanup as destructor body plus conditional delete. |

## Behavior Notes

- Button id `1` reads control `4`, copies it into a `SimpleUString`, parses an integer, and compares against `m_minValue..m_maxValue`.
- Out-of-range input opens an alert with localized string id `217`.
- Valid input calls the confirm callback with the parsed integer, then closes the dialog.
- Button id `2` closes the dialog and calls the cancel callback if present.
- Current confirmed callers use this as a stack-quantity picker for item mixing, but the callback interface is generic.

## Unresolved

- The confirm callback type is now tracked as [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md). It wraps `MixItemDialog` quantity-add behavior in current callers.
- IDA does not define the ordinary destructor at `0x00530b00` as a function even though the bytes are valid. Keep [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md) documented as a raw destructor body until the IDA database or import metadata is corrected.
- The EPD resource branch uses `DLGEXC3.EPD` with `NPAL8.PAL`; generated `L"NP"` is a string decoding issue documented in [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md).
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x00530c90` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md), while the raw destructor remains reconstructable.

## Cross-References

- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md)
- [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md)
- [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md)
- [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` and the coverage row still said 50% despite detailed layout, behavior, method-family, and unresolved-item documentation.
- Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
- Evidence: the page documents field offsets, child controls, constructor/destructor/action-handler ranges, adjustor thunks, scalar deleting destructor, callback behavior, resource caveats, and caller relationships; confidence remains below maximum because the ordinary destructor is raw bytes rather than an IDA function object and callback type naming is still generated.
