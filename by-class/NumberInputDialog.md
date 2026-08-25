*** UID:00009K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:00009K] NumberInputDialog class support: exact method bodies are emitted by registered by-memory children.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FunctionObject0;

template <class TArg>
class FunctionObjectT;

class NumberInputDialog : public DialogPane
{
public:
    NumberInputDialog(const wchar_t *promptText,
                      FunctionObjectT<unsigned long> *confirmCallback,
                      FunctionObject0 *cancelCallback,
                      int minValue,
                      int maxValue);
    virtual ~NumberInputDialog();

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    enum NumberInputDialogControlId
    {
        kNumberInputOkButtonId = 1,
        kNumberInputCancelButtonId = 2,
        kNumberInputPromptLabelId = 3,
        kNumberInputEditControlId = 4
    };

    enum
    {
        kNumberInputInvalidNumberStringId = 217,
        kNumberInputOkButtonImage = 14,
        kNumberInputCancelButtonImage = 22
    };

    FunctionObjectT<unsigned long> *m_confirmCallback;
    FunctionObject0 *m_cancelCallback;
    int m_minValue;
    int m_maxValue;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NumberInputDialog

## Status

- Confidence: very strong for recovered behavior, method boundaries, field offsets, callback ownership, vtable ownership, source placement, and resource caveats.
- Likely source: [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- Current recovered source: `source-3/simroot_v2/class_NumberInputDialog.cpp`
- Memory: [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- Class-owned read-only data: [UID:0003C8][0x006201d0-0x0062026c.NumberInputDialogVtableData](by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md)

## Responsibility

`NumberInputDialog` is a `DialogPane`-derived modal prompt for integer entry. It owns the prompt label, edit field, OK/cancel buttons, range validation, out-of-range alert, and callback dispatch.

## Layout Evidence

IDA offsets in the action handler and destructor support the following tail fields after the `DialogPane` base:

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x26c` | `m_confirmCallback` | Constructor stores arg `a3`; action handler invokes it with the parsed integer. Destructor deletes this object if present. Source type direction is an abstract one-argument numeric function object such as `FunctionObjectT<unsigned long>*`, not the concrete MixItemDialog wrapper. |
| `+0x270` | `m_cancelCallback` | Constructor stores arg `a4`; cancel action calls it with no parsed value. Current destructor evidence does not delete it, so treat it as nullable/borrowed/externally managed unless later evidence proves ownership. Source type direction is an abstract no-argument function object such as `FunctionObject0*`. |
| `+0x274` | `m_minValue` | Action handler rejects values below this field. |
| `+0x278` | `m_maxValue` | Action handler rejects values above this field. |
| child `1` | OK button | Set as default action / OK button index. |
| child `2` | cancel button | Set as cancel action / cancel button index. |
| child `3` | prompt label | Constructed from caller-provided prompt text. |
| child `4` | edit control | Focus control; text is copied and parsed as an integer. |

## Method Families

| Range | Method | Summary |
| --- | --- | --- |
| [UID:0001CV][0x00530640-0x00530b00.NumberInputDialogConstructor](by-memory/0x00530640-0x00530b00.NumberInputDialogConstructor.md) | constructor | Builds either EPF or EPD layout, adds controls, sets focus/default/cancel controls, bounds, position, and slide-open state. |
| [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md) | destructor body | Real bytes but not an IDA function object; resets vtables, deletes callback target, and jumps to base cleanup. |
| [UID:0001CY][0x00530b40-0x00530c78.NumberInputDialogActionHandler](by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md) | `OnControlCommand(int,int)` override | Confirms, validates, reports parsed value, closes, or cancels and calls the cancel callback. Exact primary-vtable slot equality with `DialogPane` resolves the inherited virtual name. |
| [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md) | destructor adjustor thunks | Class-owned ABI evidence for the secondary and tertiary destructor views: two exact `0x0b` thunks for `this - 0xa0` / decimal `160` and `this - 0xa4` / decimal `164`, referenced from vtable slots `0x00620234` / `0x00620264` and jumping to [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md). They remain `RECONSTRUCTABLE:FALSE` with blank emitters/C++; the compiler regenerates them from the class inheritance/vtable layout and virtual destructor source. |
| [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md) | scalar deleting destructor | Same cleanup as destructor body plus conditional delete. |

## Class-Owned Read-Only Data

| Range | Data | Evidence |
| --- | --- | --- |
| [UID:0003C8][0x006201d0-0x0062026c.NumberInputDialogVtableData](by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md) | Primary, secondary, and tertiary `NumberInputDialog` complete-object-locator/vtable chunks. | 2026-06-12 live IDA MCP confirms `.rdata` chunks at `0x006201d0-0x00620230`, `0x00620230-0x00620260`, and `0x00620260-0x0062026c`; constructor/raw-destructor/scalar-deleting-destructor stores to `0x006201d4`, `0x00620234`, and `0x00620264`; action-handler slot `0x0062021c -> 0x00530b40`; and successor resource literal `DLGEXC3.EPD` at `0x0062026c`. |

## Behavior Notes

- Button id `1` reads control `4`, copies it into a `SimpleUString`, parses an integer, and compares against `m_minValue..m_maxValue`.
- Out-of-range input opens an alert with localized string id `217`.
- Valid input calls the confirm callback with the parsed integer, then closes the dialog.
- Button id `2` closes the dialog and calls the cancel callback if present.
- Current confirmed callers use this as a stack-quantity picker for item mixing, but the callback interface is generic.

## Historical 2026-06-17 Source-Quality Closure

B002's source-quality pass resolves the class as a reusable modal numeric prompt under `NexusTK/ui/dialogs/NumberInputDialog.cpp`, separate from ItemDialogs callers and FunctionObject callback-wrapper templates. The class owns abstract callback fields, numeric validation state, control/action ids, layout branch selection, and destructor policy.

Accepted source-facing declarations/constants for first-draft output:

```cpp
enum NumberInputDialogControlId
{
    kNumberInputOkButtonId = 1,
    kNumberInputCancelButtonId = 2,
    kNumberInputPromptLabelId = 3,
    kNumberInputEditControlId = 4
};

enum
{
    kNumberInputInvalidNumberStringId = 217,
    kNumberInputOkButtonImage = 14,
    kNumberInputCancelButtonImage = 22
};
```

Accepted method policy:

- [UID:0001CV][0x00530640-0x00530b00.NumberInputDialogConstructor](by-memory/0x00530640-0x00530b00.NumberInputDialogConstructor.md) constructor, [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md) ordinary destructor, and [UID:0001CY][0x00530b40-0x00530c78.NumberInputDialogActionHandler](by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md) action handler now carry first-draft formal C++ with descriptive helper names.
- [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md) scalar deleting destructor remains class-owned. Its historical blank formal CPP is superseded by an exact covered-by marker while the compiler still emits the wrapper from the virtual destructor declaration and [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md) ordinary destructor body.
- [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md) adjustor thunks remain non-reconstructable compiler glue with no C++ body; their resolved class context is [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md), while the source replacement is the ordinary virtual destructor and matching vtable/inheritance layout.

Rejected alternatives:

- Caller ownership under `ItemDialogs`, `MixItemDialog`, concrete add-item/mix-item flows, or concrete `DoubleParamMemberFunctionObject<MixItemDialog,...>` fields.
- FunctionObjects ownership of the dialog class. FunctionObjects own concrete callback adapters; this class stores abstract callback pointers and invokes/deletes them according to dialog policy.
- TextEditControlPane, LanguageMan, AlertPane, or close/parse helpers owning [UID:0001CY][0x00530b40-0x00530c78.NumberInputDialogActionHandler](by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md); they are dependencies.
- Deleting `m_cancelCallback` in the destructor without new evidence.
- Preserving generated `L"NP"` palette text or disabled `this - 0x1dc` adjustor text as source-quality facts.
- Emitting handwritten C++ for [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md). The correct source-quality state is documented ignored ABI glue with `this - 0xa0` and `this - 0xa4`, not materialized thunk methods.

## 2026-08-02 B010 Accepted Class Declaration And ABI Model

### Layout, Ownership, And Inheritance

`NumberInputDialog` has exact complete size `0x27c`: direct `DialogPane` base size `0x26c` followed by four dword fields. RTTI proves `DialogPane` is the only direct source base. The EventHandler and TimerHandler views are inherited facets at `+0xa0` and `+0xa4`; adding either as a second direct base would duplicate the existing `DialogPane` layout.

| Offset | Declared field | Type and ownership |
| --- | --- | --- |
| `+0x26c` | `m_confirmCallback` | owned `FunctionObjectT<unsigned long> *`; invoked with the parsed value and deleted by the ordinary destructor |
| `+0x270` | `m_cancelCallback` | nullable borrowed `FunctionObject0 *`; invoked after cancel-close and not deleted by reviewed destructor paths |
| `+0x274` | `m_minValue` | signed `int`, inclusive lower bound |
| `+0x278` | `m_maxValue` | signed `int`, inclusive upper bound |

The three class views use primary, EventHandler, and TimerHandler vtables at object offsets `0`, `+0xa0`, and `+0xa4`. The seven-entry RTTI hierarchy includes the direct `NumberInputDialog -> DialogPane` chain and inherited EventHandler/TimerHandler facets. Constructor, ordinary destructor, and scalar-wrapper vptr stores all agree with this layout. The delete-guard size `0x27c` independently confirms the complete size.

### Source Interface

- The sole class declaration is the formal H block above. It uses the exact five source parameters and intentionally has no `DialogPane *parent` parameter.
- The destructor is public and virtual. C++ access is not encoded by the binary, but public is the highest-probability source form given public base destruction, generic heap use, and sibling dialog style.
- The inherited action virtual is protected `OnControlCommand(int controlIndex, int notifyCode)`. C++11 `override` is deliberately absent to match the source era.
- UID0001WQ declares `FunctionObjectT<TArg>::Invoke(TArg)` and `FunctionObject0::Invoke()`, supporting the callback field and call spellings used by the exact method children.
- The formal CPP block is only the class support/child insertion point. Constructor, ordinary destructor, and action bodies remain on UID0001CV, UID0001CX, and UID0001CY.

### Compiler Products Excluded From Human Source

- UID0001D0 scalar deleting wrapper is regenerated from `virtual ~NumberInputDialog()` plus the ordinary destructor body and is represented only by its covered-by marker.
- UID0001CZ adjustor thunks are regenerated from the inherited `+0xa0/+0xa4` facets and remain false/non-emitting with blank CPP/H.
- UID0003C8 vtable/RTTI data is regenerated from this declaration and uses a class-covered marker rather than raw arrays.
- Explicit vptr stores, delete-flags branches, guard-size calls, RTTI objects, and vtable arrays are compiler lowering and must not enter class-authored source.

### Score Rationale And Historical Correction

Completion `94` remains below the final barrier because whole-project compile/layout identity and original lexical/access tokens are not fully established. Confidence `95` is supported by exact `0x27c` size, direct base, seven RTTI entries, three facets, four tail fields, inherited virtual identity, and complete CPP/H routing.

The older provisional `OnButtonAction`, blank class-formal, and generic unresolved-destructor assumptions are retained above as historical stages. They are superseded by the exact `OnControlCommand` slot comparison, public virtual destructor declaration, formal class H, and child-emission route; the older evidence itself is not discarded.

## Unresolved / Below-Final Items

- Exact original callback typedef names remain unproven. Use abstract callback/function-object interface names in first-draft source; keep [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md) as caller-side evidence for the current item-mixing quantity callbacks, not as the class field type.
- IDA does not define the ordinary destructor at `0x00530b00` as a function even though the bytes are valid. Keep [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md) documented as a raw destructor body until the IDA database or import metadata is corrected.
- The EPD resource branch uses `DLGEXC3.EPD` with `NPAL8.PAL`; generated `L"NP"` is a string decoding issue documented in [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md).
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x00530c90` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md), while the raw destructor remains reconstructable.
- 2026-06-12 IDA recheck reconfirms the vtable data and class-method map together: constructor stores the three vtable bases at `0x005306aa`, `0x005306b0`, and `0x005306ba`; the raw destructor stores them at `0x00530b09`, `0x00530b0f`, and `0x00530b19`; scalar deleting destructor stores them at `0x00530c9c`, `0x00530ca2`, and `0x00530cac`; and the two adjusted vtables point through thunks that subtract `0xa0` / decimal `160` and `0xa4` / decimal `164` from `this` before jumping to `0x00530c90` (Verified with `tools/int_convert.py`).

## Cross-References

- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md)
- [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md)
- [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md)
- [UID:0003C8][0x006201d0-0x0062026c.NumberInputDialogVtableData](by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md)
- [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)

## Changes

- 2026-06-17 B002 source-quality execution:
  - Before: the class was `88/87`, still carried generated callback-type caveats as active unresolved blockers, and method C++ was blank.
  - Changed to: `COMPLETION:90`, `CONFIDENCE:91`; added report-level callback field/type ownership, control constants, action-handler naming direction, first-draft C++ policy, scalar-wrapper blank-C++ policy, and rejected ownership/type/source alternatives.
  - Evidence: B002 report-level comparison of constructor/action/destructor/scalar-wrapper pages, current resources, FunctionObject/caller docs, and generated-output defects. Exact original typedef/helper names remain below-final limitations rather than blockers for draft C++.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md) because this class is 86/82 and the parent file is 89/84. Live IDA MCP on `NexusTK.exe` confirmed constructor/action/thunk/deleting-destructor starts at `0x00530640`, `0x00530b40`, `0x00530c78`, `0x00530c83`, and `0x00530c90`; the documented ordinary destructor at `0x00530b00` remains raw bytes rather than an IDA function start and is not used as attachment proof.
- Before: completion/confidence metadata were `0/0` and the coverage row still said 50% despite detailed layout, behavior, method-family, and unresolved-item documentation.
- Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
- Evidence: the page documents field offsets, child controls, constructor/destructor/action-handler ranges, adjustor thunks, scalar deleting destructor, callback behavior, resource caveats, and caller relationships; confidence remains below maximum because the ordinary destructor is raw bytes rather than an IDA function object and callback type naming is still generated.
- 2026-06-12 A004 Batch 258: raised to `88/87` after live IDA MCP reconfirmed the class-owned `NumberInputDialog` `.rdata` vtable chunks, method slot targets, constructor/raw-destructor/scalar-deleting-destructor stores, thunk adjustments, and successor boundary. The raw destructor and generated callback type names remain documented caveats, so the score stays below final-source/audit quality, but the direct class parent now clears the strict `85/85` gate for [UID:0003C8][0x006201d0-0x0062026c.NumberInputDialogVtableData](by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md).
