** TARGET-REPORT-UID:0001CV **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Report: NumberInputDialog source-quality and first-draft C++ pass

## Final Recommendation

Recommended source placement is `NexusTK/ui/dialogs/NumberInputDialog.cpp` with declarations in the matching `NumberInputDialog` class header. The four primary target functions are `NumberInputDialog` class methods or compiler-emitted class ABI artifacts. They should no longer be treated as ItemDialogs-owned caller code, concrete MixItemDialog callback code, TextEdit code, AlertPane code, LanguageMan code, or a raw aggregate-only source unit.

Use the class page [UID:00009K] `NumberInputDialog` as the direct semantic owner/emitter for these methods. The current aggregate [UID:0001CW] is still useful as a range/index page for the contiguous binary block, but source-quality ownership belongs to the class. If the supervisor keeps the current aggregate route for tooling compatibility, the method bodies are still source-ready; the semantically preferred owner/emitter is the class.

| UID | Current score | Recommended score | Recommended owner | Recommended emitter | Reconstructable | C++ policy |
| --- | --- | --- | --- | --- | --- | --- |
| 0001CV constructor | 82/90 | 89/91 | 00009K | 00009K | TRUE | Populate first-draft constructor C++. Use descriptive/inferred callback and helper names where originals are not proven. |
| 0001CX raw destructor | 82/90 | 88/91 | 00009K | 00009K | TRUE | Populate ordinary `NumberInputDialog::~NumberInputDialog()` C++. This is source-authored destructor semantics, despite IDA not recognizing the start as a function. |
| 0001CY action handler | 82/90 | 90/91 | 00009K | 00009K | TRUE | Populate first-draft action/button handler C++. Recommended descriptive name: `OnButtonAction(int controlId, int unused)`. |
| 0001D0 scalar deleting destructor | 82/90 | 86/92 | 00009K | 00009K | TRUE, source-declared/generated-binary | Keep formal C++ blank. This wrapper is generated from the virtual/ordinary destructor declaration and should not be hand-written as a source method. |

The generated `auto-generated/NexusTK/ui/dialogs/NumberInputDialog.cpp` route exists locally but is currently an empty file because the relevant C++ blocks are blank. 0001CV, 0001CX, and 0001CY are above the active C++ entry gate once this source-quality pass is incorporated. 0001D0 is intentionally blank for compiler-wrapper reasons, not because behavior is unknown.

## Heuristic / Inference Reanalysis And Validation

### Ownership and source placement

Best recommendation: place source in `NexusTK/ui/dialogs/NumberInputDialog.cpp` and class declarations in the matching `NumberInputDialog` header, under [UID:00009K] and [UID:0000M1].

Candidates considered:

- `ItemDialogs` / MixItemDialog caller ownership: rejected. Direct constructor callers at `0x004afdce` and `0x004b03d6` are item/mix quantity flows, but they only allocate/configure the reusable numeric prompt. Callback wrapper docs [UID:000041], [UID:00014W], [UID:000319], [UID:00031A], and [UID:0002U2] show caller-side callback construction, not dialog ownership.
- `FunctionObjects` ownership: rejected. FunctionObjects own the callback adapter templates and concrete wrapper mechanics. `NumberInputDialog` owns only abstract callback pointer fields and invokes/deletes them according to dialog policy.
- `AlertPane`, `LanguageMan`, or `TextEditControlPane` ownership: rejected. Those are dependencies used by the action handler for validation failure text, alert display, and edit text extraction.
- [UID:0001CW] aggregate ownership: useful as binary-range context, but semantically too broad for direct source ownership now that [UID:00009K] is a class page above gate. If existing generation tooling requires child methods to emit through [UID:0001CW], preserve that as an implementation route, but update prose to state the direct semantic owner is [UID:00009K].

Impact: owner/emitter should be class-owned for source quality. This does not move the source file; it still emits into `NexusTK/ui/dialogs/NumberInputDialog.cpp`.

### Callback fields and signatures

Field evidence:

- `this + 0x26c`: confirm callback pointer.
- `this + 0x270`: cancel callback pointer.
- `this + 0x274`: minimum accepted numeric value.
- `this + 0x278`: maximum accepted numeric value.

Best source-quality names and types:

```cpp
FunctionObjectT<unsigned long>* m_confirmCallback;  // inferred/descriptive
FunctionObject0*               m_cancelCallback;   // inferred/descriptive
int                            m_minValue;
int                            m_maxValue;
```

The exact original typedef names are not proven. The source-quality type should be an abstract callback/function-object interface, not the concrete MixItemDialog callback wrapper. The concrete wrapper [UID:000041] captures a MixItemDialog instance, member-function pointer, adjustor, and two byte parameters, then forwards the runtime quantity argument. That makes it caller-side glue. The dialog should know only that the confirm callback accepts the entered quantity through the shared function-object ABI.

`unsigned long` is the best ABI-facing callback argument because the known concrete wrapper forwards `[ebp+8]` as an unsigned-long runtime argument. Source semantics remain "integer quantity"; comparisons against `m_minValue` and `m_maxValue` are numeric range checks. If the final class header has an existing signed `int` callback typedef, that typedef can be used, but the report-level recommendation is that the field is an abstract one-argument numeric callback.

The destructor deletes only `m_confirmCallback`. No reviewed raw or scalar destructor evidence shows deletion of `m_cancelCallback`. Best inference: confirm callbacks are owned by the prompt because known callers allocate them specifically for the submitted quantity, while cancel callbacks are nullable, borrowed, static, or otherwise externally managed. Do not silently add deletion of `m_cancelCallback` in source C++ unless later binary evidence proves a missing destructor path.

Rejected alternatives:

- Concrete `DoubleParamMemberFunctionObject<MixItemDialog,...>*` field: rejected because it would make a reusable UI dialog depend on a specific caller class.
- Plain C function pointer for confirm/cancel: rejected because the binary invokes virtual callback slots and known wrappers are heap-allocated function objects.
- Owning both callback fields: rejected because only `+0x26c` is deleted in both destructor-shaped bodies.

Impact: this resolves the prior callback-type caveat enough to populate first-draft C++ with descriptive/inferred callback typedefs.

### Numeric range fields

`+0x274` and `+0x278` are best named `m_minValue` and `m_maxValue`.

Evidence: the action handler retrieves text from child control id 4, parses it through the integer parse helper, then compares the parsed value against these two fields before either displaying the localized error string id 217 or invoking the confirm callback. That use pattern is incompatible with resource dimensions, control ids, button positions, or item metadata pointers.

Rejected alternatives:

- Layout coordinates: rejected because the fields are compared against parsed edit text, not used in control construction.
- Resource ids or string ids: rejected because localized string id 217 is immediate/helper-driven, and resource names are branch constants.
- Max-only stack count pair: rejected. Known callers may pass item stack limits, but the class-level contract is generic min/max numeric validation.

Impact: field meanings are source-quality and should be incorporated in class and constructor docs.

### Control ids and action semantics

Control/action ids are source-quality:

- `1`: OK / confirm button and default action.
- `2`: cancel button and cancel action.
- `3`: prompt label.
- `4`: edit/text input control.

The action handler should not be named `OnConfirm` in final source-quality docs. It handles both OK and Cancel, and its vtable slot is a generic button/action dispatch slot. Recommended descriptive name: `OnButtonAction(int controlId, int unused)` or, if local `DialogPane` naming prefers it, `OnCommand(int controlId, int unused)`.

Behavior:

- OK path: get text from edit control id 4, parse integer, enforce inclusive min/max range, show error alert if invalid, otherwise invoke confirm callback with the parsed value, then close/dismiss the dialog.
- Cancel path: close/dismiss the dialog, then invoke cancel callback if present.
- Other control ids: no meaningful side effects observed; source should return without action.

Rejected alternatives:

- `OnConfirm`: rejected because cancel behavior is in the same function.
- Treat id 1/id 2 as Windows `IDOK`/`IDCANCEL` imports: rejected as exact naming. The values match that convention, but these are dialog/control ids in the project's UI framework.
- Treat id 3/id 4 as action ids: rejected because constructor assigns them to label/edit child controls and handler fetches id 4 for text.

Impact: 0001CY can receive first-draft C++ with a descriptive dispatch name.

### Layout and resource branch names

The resource branch details are source-quality:

- EPF branch when `g_useEpfAssets` is true:
  - Background/art: `DLGEXC3.EPF`
  - Palette: `PAL01.PAL`
  - Dialog size: `239 x 283`
- EPD branch when `g_useEpfAssets` is false:
  - Background/art: `DLGEXC3.EPD`
  - Palette: `NPAL8.PAL`
  - Dialog size: `287 x 277`
- Button image/frame ids:
  - OK/default: image/frame 14
  - Cancel: image/frame 22
- Localized invalid-number string:
  - STR.RES id 217: `You have entered an incorrect number.`

Current generated text that uses `L"NP"` for the EPD palette branch is not source-quality; it should be corrected to `NPAL8.PAL` in docs or generated drafts. The disabled adjustor-thunk text that used `this - 0x1dc` is also not source-quality for this class; secondary destructor thunks adjust by 160 and 164 bytes.

The existing docs reviewed for this report record branch names, sizes, ids, prompt/edit controls, and button frame ids. They do not provide enough reviewed evidence to prove every branch-specific button rectangle without a fresh IDA pass. The first-draft constructor therefore uses descriptive local UI helpers for standard button placement instead of inventing exact unproven button coordinates. This caps 0001CV below 95 but does not block C++ entry.

### Helper calls and descriptive names

These helper names are recommended as descriptive source names unless a later pass proves original names:

- `sub_498C20`: `TextEditControlPane::GetInputText` or `CopyInputText`. It is the edit-control text extraction helper used on child control id 4.
- `sub_582670`: `ParseDecimalInteger` or `StringUtil::ParseInteger`. It parses the edit text into the numeric value used for min/max comparison.
- `sub_4F0380`: `LanguageMan::CopyLocalizedString` / `GetLocalizedString(out, id)`. Existing docs identify it as a string-copy lookup helper with fallback behavior.
- `sub_49FEB0`: `AlertPane` constructor/core alert creation helper. In this function it presents the invalid-number message.
- `sub_49DAD0`: `CloseDialog` / `DismissDialog`. Existing docs repeatedly treat this as a dialog close/remove helper.
- `sub_4F4AC0`: `OperatorDeleteWrapper`; source should express this as `delete this` only through compiler-generated scalar deleting destructor logic, not handwritten C++.

Rejected alternatives:

- Preserve raw `sub_` names in source C++: rejected for first-draft source quality.
- Move helper implementations into NumberInputDialog: rejected. These helpers belong to their respective UI/string/memory subsystems.
- Treat the alert message as an inline literal in source: rejected. The binary looks up STR.RES id 217.

Impact: unresolved original helper names are not blockers. They should be marked inferred/descriptive at by-* detail level and reconciled with broader subsystem naming when those docs mature.

### Destructor treatment

0001CX is an ordinary destructor-shaped body, even though IDA does not currently list `0x00530b00` as a function. Raw disassembly/bytes and vtable resets prove a destructor body at `0x00530b00-0x00530b35`, followed by padding before the action handler. It stores the primary and secondary vtables, deletes the owned confirm callback at `+0x26c` when present, and tail-calls base cleanup.

Source policy for 0001CX:

- Populate C++ as `NumberInputDialog::~NumberInputDialog()`.
- Do not write vtable stores.
- Do not write explicit base destructor calls.
- Delete only `m_confirmCallback`.
- Leave `m_cancelCallback` unmanaged unless future evidence proves ownership.

0001D0 is the MSVC scalar deleting destructor wrapper at `0x00530c90-0x00530cf7`. It repeats destructor cleanup and conditionally calls the operator-delete wrapper based on deleting flags. The vtable and xref pattern, including the primary vtable first slot and secondary adjustor thunks, identifies it as compiler-generated ABI output.

Source policy for 0001D0:

- Keep reconstructable as source-declared/generated-binary class ABI.
- Keep direct owner/emitter on the class so the vtable/destructor relationship is documented.
- Keep formal C++ blank. The source representation is the virtual destructor declaration plus the ordinary destructor body at 0001CX.

Rejected alternatives:

- Mark raw destructor ignored because IDA lacks a function entry: rejected. The bytes are source-relevant and match destructor semantics.
- Handwrite a scalar deleting destructor method: rejected. That would be decompiler-style ABI code, not source-quality C++.
- Ignore the scalar deleting destructor entirely: rejected. It is an important generated ABI artifact referenced by vtables and adjustor thunks, but the C++ block should remain blank.

### Adjustor thunks

The neighboring adjustor thunks [UID:0001CZ] remain non-reconstructable/ignored and should not get C++ bodies:

- `0x00530c78`: adjusts `this` by `-0xa0` / 160 bytes and jumps to the scalar deleting destructor.
- `0x00530c83`: adjusts `this` by `-0xa4` / 164 bytes and jumps to the scalar deleting destructor.

This validates the multi-inheritance or secondary-base vtable ABI shape but does not change source code placement for the destructor.

### Score and final-C++ impact

This pass resolves the code-entry blockers around callback abstraction, min/max fields, action semantics, resource branch names, raw destructor treatment, scalar wrapper treatment, and source placement. Remaining limitations are exact original typedef/helper names and exact branch-specific button placement coordinates, because IDA MCP was unavailable and the reviewed docs do not prove those details. These limitations cap scores below 95 but do not block first-draft C++ for 0001CV, 0001CX, or 0001CY.

## First-Draft C++ Recommendations

The following draft intentionally uses source-quality descriptive names. The names `FunctionObjectT`, `FunctionObject0`, `WideString`, `SetDialogArt`, `CreatePromptLabel`, `CreateTextEdit`, `CreateStandardButtonsForLayout`, `GetChildControl`, `ParseDecimalInteger`, `ShowModalAlert`, and `CloseDialog` should be reconciled with existing project types/helpers before final source landing. They are better source placeholders than raw decompiler names because the binary behavior and ownership are already understood.

Recommended shared declarations/constants for the class or file-level source:

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

### UID:0001CV - constructor

Populate a constructor body in the 0001CV C++ block. Signature is inferred/descriptive and should be matched to the final class declaration.

```cpp
NumberInputDialog::NumberInputDialog(DialogPane* parent,
                                     const wchar_t* promptText,
                                     FunctionObjectT<unsigned long>* confirmCallback,
                                     FunctionObject0* cancelCallback,
                                     int minValue,
                                     int maxValue)
    : DialogPane(parent),
      m_confirmCallback(confirmCallback),
      m_cancelCallback(cancelCallback),
      m_minValue(minValue),
      m_maxValue(maxValue)
{
    if (g_useEpfAssets)
    {
        SetDialogArt(L"DLGEXC3.EPF", L"PAL01.PAL", 239, 283);
        CreatePromptLabel(kNumberInputPromptLabelId, promptText);
        CreateTextEdit(kNumberInputEditControlId);
        CreateStandardButtonsForLayout(kNumberInputOkButtonId,
                                       kNumberInputCancelButtonId,
                                       kNumberInputOkButtonImage,
                                       kNumberInputCancelButtonImage);
    }
    else
    {
        SetDialogArt(L"DLGEXC3.EPD", L"NPAL8.PAL", 287, 277);
        CreatePromptLabel(kNumberInputPromptLabelId, promptText);
        CreateTextEdit(kNumberInputEditControlId);
        CreateStandardButtonsForLayout(kNumberInputOkButtonId,
                                       kNumberInputCancelButtonId,
                                       kNumberInputOkButtonImage,
                                       kNumberInputCancelButtonImage);
    }

    SetDefaultAction(kNumberInputOkButtonId);
    SetCancelAction(kNumberInputCancelButtonId);
    SetInitialFocus(kNumberInputEditControlId);
    CenterOnParentOrScreen();
    Open();
}
```

Notes for supervisor incorporation:

- The exact original constructor parameter names are not proven. The source-level responsibilities are proven enough for a descriptive first draft.
- If final UI helper docs expose exact label/edit/button rectangles, replace the generic `CreatePromptLabel`, `CreateTextEdit`, and `CreateStandardButtonsForLayout` helpers with those concrete calls.
- Do not use `L"NP"` for the EPD palette branch. Use `L"NPAL8.PAL"`.

### UID:0001CX - raw destructor

Populate an ordinary destructor body in the 0001CX C++ block.

```cpp
NumberInputDialog::~NumberInputDialog()
{
    delete m_confirmCallback;
    m_confirmCallback = 0;
}
```

Notes for supervisor incorporation:

- This source body regenerates the owned confirm-callback delete observed in both destructor-shaped binary bodies.
- Do not delete `m_cancelCallback` unless later binary evidence proves ownership. Current destructor evidence does not.
- Do not include vtable stores or explicit base cleanup in source C++.

### UID:0001CY - action handler

Populate a generic button/action handler body in the 0001CY C++ block. Recommended method name is inferred/descriptive: `OnButtonAction`. If `DialogPane` has an established virtual name such as `OnCommand`, use that local convention and keep the behavior unchanged.

```cpp
void NumberInputDialog::OnButtonAction(int controlId, int /*unused*/)
{
    if (controlId == kNumberInputOkButtonId)
    {
        WideString inputText;
        TextEditControlPane* edit =
            static_cast<TextEditControlPane*>(GetChildControl(kNumberInputEditControlId));

        if (edit != 0)
            edit->GetInputText(inputText);

        const int value = ParseDecimalInteger(inputText.c_str());

        if (value < m_minValue || value > m_maxValue)
        {
            WideString message;
            g_pLanguageMan->CopyLocalizedString(message, kNumberInputInvalidNumberStringId);
            ShowModalAlert(message.c_str());
            return;
        }

        if (m_confirmCallback != 0)
            m_confirmCallback->Invoke(static_cast<unsigned long>(value));

        CloseDialog();
        return;
    }

    if (controlId == kNumberInputCancelButtonId)
    {
        CloseDialog();

        if (m_cancelCallback != 0)
            m_cancelCallback->Invoke();
    }
}
```

Notes for supervisor incorporation:

- The order "confirm callback, then close" follows existing 0001CY prose. The cancel path closes first, then invokes the cancel callback.
- `ShowModalAlert` should lower to the existing AlertPane constructor path using localized string id 217.
- `ParseDecimalInteger` should lower to the existing integer parse helper at `0x00582670`.
- `GetInputText` should lower to the edit-control text extraction path through `0x00498c20`.

### UID:0001D0 - scalar deleting destructor

Do not populate formal C++ for 0001D0.

Recommended report/prose wording for the page:

```cpp
// No RECONSTRUCTION_CPP body.
// MSVC emits this scalar deleting destructor from the virtual
// NumberInputDialog::~NumberInputDialog() declaration and body.
```

This is intentionally blank C++ with `RECONSTRUCTABLE:TRUE` as source-declared/generated-binary ABI output.

## Exact Supervisor-Owned Replacement Rows

Do not edit `by-memory/-coverage-report.md` directly from this B-agent report. If the supervisor accepts class ownership, replace the four primary rows with:

```text
    - [UID:0001CV][0x00530640-0x00530b00.NumberInputDialogConstructor](by-memory/0x00530640-0x00530b00.NumberInputDialogConstructor.md) : reconstructable : 89% : very strong : Source-quality pass resolves NumberInputDialog constructor placement under the class/file route, abstract confirm/cancel callback fields, min/max range fields, control ids 1/2/3/4, EPF/EPD resource branches, and palette names; first-draft C++ should be populated with descriptive/inferred helper names while exact original UI helper typedefs remain unproven.
    - [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md) : reconstructable : 88% : very strong : Source-quality pass confirms the IDA-missing function entry is an ordinary NumberInputDialog destructor body that deletes only the owned confirm callback at +0x26c and relies on compiler/base cleanup; first-draft `NumberInputDialog::~NumberInputDialog()` C++ should be populated, with no vtable stores or scalar-delete logic.
    - [UID:0001CY][0x00530b40-0x00530c78.NumberInputDialogActionHandler](by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md) : reconstructable : 90% : very strong : Source-quality pass resolves the virtual action handler as a generic OK/cancel button dispatch, recommended descriptive name `OnButtonAction`, with edit control id 4 text extraction, integer parse, inclusive min/max validation, STR.RES id 217 AlertPane error path, confirm callback invocation with parsed quantity, cancel callback invocation, and close/dismiss behavior; first-draft C++ should be populated.
    - [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md) : reconstructable : 86% : very strong : Source-quality pass confirms this is the MSVC scalar deleting destructor wrapper for NumberInputDialog, referenced by the primary vtable and secondary adjustor thunks; keep class-owned/emitting as source-declared/generated-binary ABI output, but keep formal C++ blank because the ordinary virtual destructor source regenerates this wrapper.
```

If the supervisor keeps the current aggregate route for tool compatibility, use the same row text but replace prose references to "class/file route" with "aggregate-to-class/file route" and keep `EMITTER_UIDS:0001CW` only as a mechanical route. The source-quality owner should still be documented as [UID:00009K].

Optional aggregate row if [UID:0001CW] is updated from source-emitting parent to non-emitting range/index context:

```text
    - [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md) : ignored : 88% : very strong : Reviewed NumberInputDialog contiguous method/vtable-adjacent range index; direct source bodies belong to class-owned children 0001CV, 0001CX, 0001CY, and source-declared/generated-binary wrapper 0001D0, while adjustor thunks 0001CZ remain ignored. Preserve this page as range/context documentation for resource branches, vtable relationships, callback fields, and padding; do not emit duplicate aggregate C++.
```

If the aggregate remains reconstructable because current generation tooling needs it as a child collector, use this row instead:

```text
    - [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md) : reconstructable : 89% : very strong : Reviewed NumberInputDialog contiguous method range and source route; child method bodies should carry formal C++ for constructor, ordinary destructor, and action handler, scalar deleting destructor remains blank as generated ABI, adjustor thunks remain ignored, and this aggregate should not duplicate child method bodies beyond the generation system's required child insertion route.
```

Optional class coverage row if [UID:00009K] is rescored:

```text
    - [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md) : reconstructable : 90% : very strong : Source-quality pass resolves NumberInputDialog as a reusable modal numeric prompt under `NexusTK/ui/dialogs`, with abstract confirm/cancel callback fields, owned confirm-callback deletion, non-owning/externally managed cancel callback, min/max integer validation fields, control ids 1/2/3/4, EPF/EPD resource branches, localized invalid-number AlertPane path, and compiler-generated scalar deleting destructor policy.
```

Optional file coverage row if [UID:0000M1] is rescored:

```text
    - [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md) : reconstructable : 91% : very strong : Source module placement is `NexusTK/ui/dialogs/NumberInputDialog.cpp` with class declarations in the matching dialog header; NumberInputDialog remains separate from ItemDialogs callers and FunctionObject callback wrappers, and first-draft C++ is now ready for constructor, ordinary destructor, and action handler while scalar deleting destructor output remains compiler-generated.
```

## By-* Support Docs The Supervisor Should Update

- [UID:0001CV] constructor page: update owner/emitter to [UID:00009K] if accepting class ownership; otherwise explicitly state [UID:0001CW] is only a mechanical route. Add first-draft constructor C++. Replace unresolved callback caveat with abstract callback field recommendation. Record `m_confirmCallback` at `+0x26c`, `m_cancelCallback` at `+0x270`, `m_minValue` at `+0x274`, `m_maxValue` at `+0x278`, control ids 1/2/3/4, EPF/EPD branch names, sizes, and palette correction `NPAL8.PAL`.
- [UID:0001CX] raw destructor page: update owner/emitter to [UID:00009K] if accepting class ownership. Add ordinary destructor C++. State that the missing IDA function entry does not block reconstruction. State only `m_confirmCallback` is deleted; `m_cancelCallback` is invoked by cancel path but not deleted by observed destructor code.
- [UID:0001CY] action handler page: update owner/emitter to [UID:00009K] if accepting class ownership. Add first-draft button/action handler C++. Rename/recommend away from `OnConfirm`; use `OnButtonAction` or local `DialogPane` virtual naming. Record OK path, cancel path, edit text helper, parse helper, min/max checks, LanguageMan string id 217, AlertPane path, close helper, and callback invocation order.
- [UID:0001D0] scalar deleting destructor page: update owner/emitter to [UID:00009K] if accepting class ownership. Keep formal C++ blank. State it is source-declared/generated-binary output from the virtual/ordinary destructor, with optional operator delete through `sub_4F4AC0`.
- [UID:0001CW] aggregate page: convert to non-emitting range/index context or keep only as mechanical child collector. Add the source-quality owner distinction: the class [UID:00009K] owns the methods; the aggregate records the contiguous binary block, padding, vtable relationships, resource branch summary, and adjustor-thunk/scalar-wrapper context. Remove "final C++ remains blank because callback declarations unresolved" as an active blocker.
- [UID:00009K] class page: update field declarations and ownership notes for callbacks/min/max. Add the generic button handler name recommendation, resource/control ids, owned confirm-callback destructor behavior, non-owning cancel-callback caveat, and scalar deleting destructor blank-C++ policy. Mark concrete MixItemDialog callback wrapper names as caller-side examples, not class field types.
- [UID:0000M1] file page: state that `NumberInputDialog.cpp` should receive constructor/destructor/action handler source, while caller-specific callback wrappers remain in ItemDialogs/FunctionObjects. Mention the currently generated file is empty only because C++ blocks are blank, not because the source route is absent.
- [UID:0001RJ] resources page: preserve `DLGEXC3.EPF`/`PAL01.PAL` and `DLGEXC3.EPD`/`NPAL8.PAL`, dialog sizes, button image ids 14/22, control ids, and STR.RES id 217 text. Flag any generated `L"NP"` palette string as stale/wrong.
- [UID:0001CZ] adjustor thunks page: no C++ body; keep ignored. Ensure offsets remain 160 and 164 bytes, not the stale `0x1dc` note.
- FunctionObject support pages [UID:000041], [UID:00014W], [UID:0001WQ], [UID:0000JO], [UID:0001Q9]: no ownership move. If touched, clarify that concrete wrappers are examples of objects passed into NumberInputDialog, while the dialog stores abstract callback pointers.
- ItemDialogs caller pages [UID:0000KE], [UID:000319], [UID:00031A], [UID:0002U2]: no source move into NumberInputDialog. If touched, keep them as caller/quantity-flow docs that allocate/configure the dialog and its confirm callback.
- TextEdit/LanguageMan/AlertPane helper pages: no ownership move. If touched, cross-reference their helper usage from 0001CY using descriptive names rather than raw `sub_` names.

## Validation / Readback

IDA MCP availability check was attempted and failed:

> Executable block R001 was removed from this report and preserved verbatim in [0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality-removed.md](0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Local generated-output check:

> Executable block R002 was removed from this report and preserved verbatim in [0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality-removed.md](0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Report readback and ASCII check after creation:

> Executable block R003 was removed from this report and preserved verbatim in [0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality-removed.md](0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001CV"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001CV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
