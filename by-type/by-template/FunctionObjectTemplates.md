*** UID:0001WQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FunctionObjects.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "LObject.h"

class FunctionObject : public LObject
{
public:
    virtual ~FunctionObject() {}
    virtual void Invoke(unsigned long value) = 0;
    virtual unsigned int GetObjectSize() const = 0;
};

class FunctionObject0 : public LObject
{
public:
    virtual ~FunctionObject0() {}
    virtual void Invoke() = 0;
    virtual unsigned int GetObjectSize() const = 0;
};

template <class TArg>
class FunctionObjectT : public LObject
{
public:
    virtual ~FunctionObjectT() {}
    virtual void Invoke(TArg value) = 0;
    virtual unsigned int GetObjectSize() const = 0;
};

template <class TMember, class TObject>
class PlainMemberFunctionObject0 : public FunctionObject0
{
public:
    PlainMemberFunctionObject0(TMember callback, int thisAdjust, TObject *object)
        : m_callback(callback), m_thisAdjust(thisAdjust), m_object(object)
    {
    }

    virtual void Invoke()
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)();
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
};

template <class TMember, class TObject, class TArg>
class PlainMemberFunctionObject : public FunctionObjectT<TArg>
{
public:
    PlainMemberFunctionObject(TMember callback, int thisAdjust, TObject *object)
        : m_callback(callback), m_thisAdjust(thisAdjust), m_object(object)
    {
    }

    virtual void Invoke(TArg value)
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(value);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
};

template <class TMember, class TObject, class TArg>
class PlainMemberFunctionObjectT : public FunctionObjectT<TArg>
{
public:
    PlainMemberFunctionObjectT(TMember callback, int thisAdjust, TObject *object)
        : m_callback(callback), m_thisAdjust(thisAdjust), m_object(object)
    {
    }

    PlainMemberFunctionObjectT(TObject *object, TMember callback)
        : m_callback(callback), m_thisAdjust(0), m_object(object)
    {
    }

    virtual void Invoke(TArg value)
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(value);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
};

template <class TMember, class TObject, class TArg0, class TArg1>
class DoubleParamMemberFunctionObject0 : public FunctionObject0
{
public:
    DoubleParamMemberFunctionObject0(TMember callback,
                                     int thisAdjust,
                                     TObject *object,
                                     TArg0 arg0,
                                     TArg1 arg1)
        : m_callback(callback),
          m_thisAdjust(thisAdjust),
          m_object(object),
          m_arg0(arg0),
          m_arg1(arg1)
    {
    }

    virtual void Invoke()
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(m_arg0, m_arg1);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
    TArg0 m_arg0;
    TArg1 m_arg1;
};

template <class TMember, class TObject, class TInvokeArg, class TArg0, class TArg1>
class DoubleParamMemberFunctionObject : public FunctionObjectT<TInvokeArg>
{
public:
    DoubleParamMemberFunctionObject(TMember callback,
                                    int thisAdjust,
                                    TObject *object,
                                    TArg0 arg0,
                                    TArg1 arg1)
        : m_callback(callback),
          m_thisAdjust(thisAdjust),
          m_object(object),
          m_arg0(arg0),
          m_arg1(arg1)
    {
    }

    virtual void Invoke(TInvokeArg value)
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(value, m_arg0, m_arg1);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
    TArg0 m_arg0;
    TArg1 m_arg1;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FunctionObject Templates

## Status

- Confidence: strong for template-support role; medium for final original header name.
- Likely owner: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Meta topic: [UID:0001Q9][client_callback_dispatch](by-meta/client_callback_dispatch.md)
- Rebuild handling: `source-declared/generated-binary`; the shared template declarations must exist in reconstructed source, but individual emitted instantiations should normally be regenerated by the compiler.

## Template Family

The client uses small callback objects to store a member function pointer, a target object pointer, optional `this` adjustment, and optional captured arguments. These objects are installed into vtables and dispatched through tiny `Invoke` methods.

Likely declaration families:

```cpp
class FunctionObject;
class FunctionObject0;

template <class TArg>
class FunctionObjectT;

template <class TMember, class TObject>
class PlainMemberFunctionObject0;

template <class TMember, class TObject, class TArg>
class PlainMemberFunctionObject;

template <class TMember, class TObject, class TArg>
class PlainMemberFunctionObjectT;

template <class TMember, class TObject, class TBound0, class TBound1>
class DoubleParamMemberFunctionObject0;
```

The exact original template names may differ, but IDA decompilation, vtable symbols, and current project docs preserve enough type information to reconstruct the owner and call shape.

B014 source-quality verification for [UID:000040][DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528](by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md) supports this source-facing declaration shape for the zero-call-argument double-bound member wrapper. This is a reconstruction direction for the shared template declaration, not a claim that the exact header basename or final template spelling is proven:

```cpp
template <class TMember, class TObject, class TArg0, class TArg1>
class DoubleParamMemberFunctionObject0 : public FunctionObject0 {
public:
    DoubleParamMemberFunctionObject0(TMember callback,
                                     int thisAdjust,
                                     TObject *object,
                                     TArg0 arg0,
                                     TArg1 arg1)
        : m_callback(callback),
          m_thisAdjust(thisAdjust),
          m_object(object),
          m_arg0(arg0),
          m_arg1(arg1)
    {
    }

    virtual void Invoke()
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(m_arg0, m_arg1);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
    TArg0 m_arg0;
    TArg1 m_arg1;
};
```

The concrete [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) page should therefore remain generated-template proof/comment-only at target level; the reusable source above is the human C++ that should cause the compiler to re-emit the tiny invoke wrapper.

The same target-level policy applies to the concrete `PlainMemberFunctionObjectT<MusicControlDialog, String>` invoke wrapper. [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md) may carry a formal comment-only no-code proof because B001 current MCP evidence proves the vtable slot, construction binding, and wrapper body; the reusable source stays in the shared template declaration and the concrete MusicControlDialog construction site.

The same accepted invoke-wrapper policy now applies to the concrete `PlainMemberFunctionObject0<Application>` invoke wrapper. [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) may carry a formal comment-only generated-template proof because B002 MCP session `d4d50b81` proves the 13-byte wrapper body, zero code callers, vtable slot `0x00612e4c`, sibling size slot `0x00612e50`, and [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md) construction store `0x00464ec6`. The reusable source stays in the shared template declaration and the concrete binding remains in the Application construction site.

The sibling Application object-size virtual follows that same target-level generated-binary marker model. [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) may carry a formal comment-only object-size proof because B008 MCP session `d4d50b81` proves the exact six-byte body, `0x18` / decimal `24` object size, no callees, vtable slot `0x00612e50`, and data-only callback refs. Reusable source remains the shared `PlainMemberFunctionObject0` declaration and Application construction site, not a handwritten `return 24;` target body.

The same accepted invoke-wrapper policy applies to the concrete `DoubleParamMemberFunctionObject` MixItemDialog quantity callback wrapper. [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) may carry a formal comment-only generated-template proof because B012 MCP session `c9671f69` proves the exact `0x21` / 33-byte wrapper, no direct code callers, vtable slot `0x0061a3bc -> 0x004b0880`, concrete vtable name `??_7?$DoubleParamMemberFunctionObject@P8MixItemDialog@@AEXKCE@ZV1@CE@@6B@`, construction stores `0x004afd62/0x004afd68` and `0x004b0370/0x004b0376`, and bound callback target [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md). The reusable source remains the shared FunctionObjects template declaration and the concrete class [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md); [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) remains the generated source root, not the exact wrapper's direct owner. Do not emit a decompiler-shaped concrete wrapper body for UID00014W.

The same accepted invoke-wrapper policy applies to the shared one-argument `PlainMemberFunctionObject` / `PlainMemberFunctionObjectT` body. [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) may carry a formal comment-only generated-template proof because B010 MCP session `279422f0` proves the exact `0x11` / 17-byte wrapper, byte sequence `55 8b ec 8b c1 8b 48 10 03 48 0c 8b 40 08 5d ff e0`, unique signature `55 8B EC 8B C1 8B 48 ? 03 48 ? 8B 40 ? 5D FF E0`, field-offset behavior through callback pointer `+0x08`, adjustment `+0x0c`, target object `+0x10`, no direct callees/callers, and seven vtable slots at `0x006187f4`, `0x0061ff7c`, `0x00620058`, `0x006200a0`, `0x00620190`, `0x00622d00`, and `0x0062ddf4`. The reusable source remains the shared FunctionObjects template declaration; [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), NewUser/CreateUser dialogs, Nexonclub dialogs, and TerminalPane are construction/consumer contexts, not owners of the folded invoke body.

Scalar deleting destructor targets follow a stricter no-code policy than proven invoke wrappers. B006 session `398b87c1` reconfirmed [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md) as the generic `FunctionObjectT<String>` scalar deleting destructor reached only through vtable slot `0x0061fcd4`, with no direct code callers/refs and no endpoint pointer route. B007 session `b009_0001Q4_20260628` reconfirmed [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) as the const-reference string callback destructor pair: two exact `0x3e` / decimal `62` functions, vtable/data refs at `0x0061ff58`, `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4`, no direct callers, no endpoint refs, delete-size immediates `4` and `0x18` / decimal `24`, and concrete create-user/Nexonclub consumer construction sites. B007 session `d4d50b81` reconfirmed [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) as the `FunctionObject0` 24-byte scalar deleting destructor metadata: exact `0x3e` / decimal `62` body, delete-size constant `0x18` / decimal `24`, vtable/data-only refs from the local `FunctionObject0` and `PlainMemberFunctionObject0<Application>` tables, no code callers/refs, and endpoint/padding negatives. B010 session `c9671f69` reconfirmed [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md) as the `FunctionObject0` `0x04` guard-size scalar deleting destructor metadata: exact `0x3e` / decimal `62` body, guard size `0x04` / decimal `4`, one `FunctionObject0::vftable` data ref at `0x0061262c`, no code callers/refs, no endpoint refs, no raw endpoint pointer route, and padding-separated range boundaries.

Pages such as [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md), [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md), [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md), [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md), [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md), [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md), and [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md) should remain source-declared/generated-binary with blank formal C++ and target prose no-code proof unless a future supervisor policy explicitly changes destructor glue handling. For accepted non-emitting scalar deleting destructor metadata, blank formal C++ should be paired with blank `EMITTER_UIDS:` unless a supervisor explicitly approves nonblank formal marker content. Their human-written source representation is the shared `FunctionObjectT<T>` / `FunctionObject0` / `FunctionObject` template declaration and destructor semantics, not a handwritten emitted deleting-destructor body.

## FunctionObject0 Compiler-Product Regeneration Proof

- The existing formal H declaration is the sole human-authored source authority for the base abstract callback class: `FunctionObject0 : public LObject`, inline virtual destructor, pure `Invoke()`, then pure `GetObjectSize() const`. It remains C++03-compatible and is not duplicated in target by-memory H channels.
- Dated live MCP session `supervisor_uid0000od_rollbackverify_20260817` verifies [UID:000482][0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer](by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md) as bytes `e0 21 64 00`, SHA256 `A3F68AF9435AEF06EACE678C843830D3114FA98A88CF2C465E1C3D78E03C1F88`, pointing to decorated FunctionObject0 COL `0x006421e0`.
- The COL references TypeDescriptor payload `.?AVFunctionObject0@@` and a two-base hierarchy whose base-array order is FunctionObject0 then `LObject`; the self base descriptor PMD is `{0,-1,0}`. This is the exact compiler RTTI consequence of the inheritance line in the formal declaration.
- [UID:0003OE][0x0061262c-0x00612640.FunctionObject0VtableData](by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md) has SHA256 `62833EE08E31F1AE254B4622E593AE9D4F3070A0DC469258B89A28CEBECA9F7A` and slots `0x004672c0`, `0x004f4b10`, `0x0041b6c0`, `0x005ca28c`, `0x005ca28c`. The inherited three-slot prefix plus the declaration's two pure methods accounts for all five entries in exact source order.
- Vptr stores at `0x004671f6` and `0x004672c6` prove the table is live compiler output. UID000327/UID000328 remain non-emitting scalar deleting-destructor glue; their behavior follows from virtual destruction and must not be handwritten here.
- Direct compiler-product ownership remains [UID:00005L][FunctionObject0](by-class/FunctionObject0.md) through [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md). UID00005L projects the locator marker followed by the vtable marker through `[[CHILDREN]]`; this template page continues to emit exactly one complete H declaration and no raw RTTI/vtable storage.
- No formal CPP/H source change is required on this page for UID000482. The evidence addition closes the regeneration route while retaining `88/90`; exact historical header basename, template spelling, compiler flags, and linker folding policy remain broader confidence limits.

## Known Instantiations

| Compiler-template class doc | Address evidence | Consumer |
| --- | --- | --- |
| shared callback-template scalar deleting destructor support | [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) | Shared `FunctionObjects` callback vtables for PopupMenu, MixItemDialog, NexonclubRegistrationDialog, and TerminalPane; base `FunctionObject::vftable` uses sibling [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md). |
| shared one-argument `PlainMemberFunctionObject` / `PlainMemberFunctionObjectT` invoke wrapper, with concrete popup user [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md) | [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md), seven vtable slots at `0x006187f4`, `0x0061ff7c`, `0x00620058`, `0x006200a0`, `0x00620190`, `0x00622d00`, and `0x0062ddf4` | [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) source route; [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), NewUser/CreateUser dialogs, Nexonclub dialogs, and TerminalPane are construction/consumer contexts. UID00011X may carry the formal comment-only generated-template marker; do not emit a decompiler-shaped wrapper body. |
| `PlainMemberFunctionObjectT<void (__thiscall CreateUserDialogPane::*)(const StringBaseW&), CreateUserDialogPane, const StringBaseW&>` | [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md), vtable at `0x00620094`, constructor stores at `0x0052e9c1-0x0052e9d5`, member target [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md) | [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md) owns the concrete feature binding; [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md) owns the construction source. UID0001WQ remains the reusable template declaration carrier, while UID0004WH is non-emitting compiler-generated support. |
| [UID:0004W2][PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_](by-class/PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_.md) | Concrete 24-byte object; [UID:0004W4][0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer](by-memory/0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer.md); [UID:0004W5][0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData](by-memory/0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData.md); shared invoke slot UID00011X at `0x0062ddf4`; installer `0x0058b567` | [UID:0000OI][TerminalPane](by-file/TerminalPane.md) owns feature construction/binding to [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md); UID0001WQ remains the sole reusable declaration carrier and [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) is the generated utility root. |
| [UID:0000AJ][PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_](by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md) | [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md), [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md), vtable slot [UID:0003OF][0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData](by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md) | [UID:0000HG][Application](by-file/Application.md), with concrete deferred-exit construction in [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md). Siblings [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) and [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md) are base `FunctionObject0` scalar destructor metadata, not part of this target-level invoke/object-size marker pair; UID000328 is the `0x04` guard-size `FunctionObject0::vftable` variant. |
| `PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>` | [UID:0003P4][0x0061d234-0x0061d24c.BaramAppCallbackVtableData](by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md), vtable `0x0061d238`, shared invoke [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md), shared 24-byte object-size [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) | [UID:0000HG][Application](by-file/Application.md) owns the concrete startup construction in [UID:0002H7][0x004f5fb0-0x004f6490.BaramAppStartup](by-memory/0x004f5fb0-0x004f6490.BaramAppStartup.md) and private member target [UID:0002Q0][0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory](by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md). UID0001WQ owns only the reusable template declaration; UID0003P4 remains compiler-generated data with a no-raw-table marker. |
| [UID:0000AL][PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6](by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md) | [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md), [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md) | [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) |
| [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md) | [UID:0003DF][0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData](by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md), constructor store `0x0055388f`, member target `0x005534a0` | [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md) |
| Versatile alert unsigned-long result callback | [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md), constructor callers `0x005301de` and `0x0058b5c5`, callback invoke slot `+0x0c` | [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md) / [UID:0000HE][AlertPanes](by-file/AlertPanes.md); source direction is `FunctionObjectT<unsigned long>*` or conservative `FunctionObject*` until final template spelling is coordinated. |
| `ConfirmInputPane` accept callback | [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md), [UID:000366][0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction](by-memory/0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction.md), destructor release paths [UID:000365][0x004f29d0-0x004f2a05.ConfirmInputPaneCompleteDestructor](by-memory/0x004f29d0-0x004f2a05.ConfirmInputPaneCompleteDestructor.md) / [UID:00036G][0x004f2fb0-0x004f3017.ConfirmInputPaneScalarDeletingDestructor](by-memory/0x004f2fb0-0x004f3017.ConfirmInputPaneScalarDeletingDestructor.md) | [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md) owns `FunctionObject0 *m_acceptAction` at `+0x108`; drop/give call sites pass the concrete [UID:000040][DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528](by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md) object after binding `UserPane`, slot, and all-items mode. |
| [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md) | [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md), vtable slot `0x0061a3bc -> 0x004b0880`, construction stores `0x004afd62/0x004afd68` and `0x004b0370/0x004b0376` | [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) / [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md); physically interleaved with [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) tail, but exact wrapper ownership/emission routes through [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md) and source root [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md). UID00014W may carry a formal comment-only marker when the vtable, construction stores, and bound target are proven. |
| [UID:000040][DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528](by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md) | [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md), [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) | [UID:0000P1][UserPane](by-file/UserPane.md) drop/give confirmations |
| [UID:00005M][FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____](by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md) | `0x0052a460` | String callback base support; also preserves the [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) type spelling. |
| [UID:00005N][FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___](by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md) | [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) | Const-reference string callback base support; also preserves the [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) type spelling. The exact scalar deleting destructor page is non-emitting metadata with blank formal C++ and blank `EMITTER_UIDS:`. |

### BaramApp Startup Callback Instantiation Detail

- The exact decorated vtable and RTTI type descriptor resolve the specialization as `PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>`. This is a zero-call-argument wrapper around a private BaramApp member; Hex-Rays' incidental pointer-return type for the target is contradicted by the member-pointer encoding.
- Current saved-IDB evidence from active database `1da2b2ae`, SHA256 `3892BDA899A18612985539399C9AC1C97B5AE6F7F9FD5D1DF2859C96472798D`, proves the exact [UID:0003P4][0x0061d234-0x0061d24c.BaramAppCallbackVtableData](by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md) table dwords: COL pointer `0x0064a028`, 24-byte scalar deleting destructor `0x004671f0`, inherited `LObject` slots `0x004f4b10`/`0x0041b6c0`, zero-argument invoke `0x004671a0`, and object-size return `0x004673f0`.
- [UID:0002H7][0x004f5fb0-0x004f6490.BaramAppStartup](by-memory/0x004f5fb0-0x004f6490.BaramAppStartup.md) allocates `0x18` bytes, stores vtable `0x0061d238` at `+0`, member target `0x004f5f50` at `+8`, zero `this` adjustment at `+0x0c`, and the live BaramApp object at `+0x10`. The vtable and target each have exactly one inbound construction-store route.
- Human-source placement keeps the reusable `PlainMemberFunctionObject0` declaration in `util/FunctionObjects.h`, declares private `BaramApp::OpenTerminalPaneAfterStartupLogo` in `app/Application.h`, and performs the concrete binding in `app/Application.cpp`. The compiler emits UID0003P4 RTTI/vtable data.
- Negative policy: do not create a BaramApp-specific template declaration, raw vtable/COL array, handwritten invoke/object-size wrapper, or scalar deleting destructor. Do not transfer feature construction ownership from Application to FunctionObjects. The target's formal marker documents regeneration without duplicating source.

### CreateUserDialogPane Registration Callback Instantiation Detail

- The decorated vtable type resolves the concrete object as `PlainMemberFunctionObjectT<void (__thiscall CreateUserDialogPane::*)(const StringBaseW&), CreateUserDialogPane, const StringBaseW&>`. This is the three-template-parameter form declared above, not the older two-argument shorthand that appeared in earlier target prose.
- [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md) allocates exactly `0x18` / 24 bytes. Its stores install vtable `0x00620094`, write [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md) at object offset `+0x08`, write a zero member-function adjustment at `+0x0c`, and write the captured `CreateUserDialogPane *` at `+0x10`.
- [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md) covers `0x00620090-0x006200a8`: complete-object-locator pointer `0x0064cb04` followed by the five-slot concrete vtable. The shared const-wide-string scalar destructor, support virtuals, folded invoke wrapper, and object-size behavior are compiler products of this template declaration and the concrete construction site.
- The sole vtable data reference is the store at `0x0052e9c1`. The callback object is passed to the `NexonclubRegistrationDialog` constructor, stored at dialog offset `+0x26c`, invoked on cancel and successful registration, and released by the dialog destructor.
- [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md) copies a non-empty callback string into `CreateUserDialogPane` offset `+0x27c` and then unconditionally sends the create-character request. The feature behavior belongs to [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md); it does not move the reusable template or compiler data into the CreateUserDialogPane source.
- Source policy: use the shared human-written declaration plus the concrete local typedef/construction expression in UID00046O. Keep UID0004WH blank-formal and non-emitting. Do not handwrite the RTTI/vtable array, shared scalar deleting destructor, folded invoke wrapper, object-size method, or decompiler field stores.

### TerminalPane Instantiation Detail

- Decorated RTTI/vtable names resolve the exact specialization as `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>`; the method type is `void`, and the argument is `unsigned long`.
- Construction allocates 24 bytes. The member-function target begins at `+0x08`, the secondary member-function word at `+0x0c` is zero for this binding, and the adjusted object pointer is stored at `+0x10`.
- `TerminalPane::OnTimer` is the feature construction site. It installs the concrete vptr at `0x0058b567`, stores `TerminalPane::OnReconnectOrLeave` at `0x0058b56d`, and passes the callback object into the reconnect/leave alert builder.
- UID0004W4 stores complete-object-locator pointer `0x00651368`; UID0004W5 contains five slots for shared scalar destructor, support virtual, no-op virtual, folded `Invoke(unsigned long)`, and object-size behavior. These are compiler outputs regenerated from this shared declaration plus the concrete binding, not handwritten arrays.
- Shared [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) and [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) support remain same-or-greater and are not reowned by TerminalPane.
- Healthy MCP session `9b0396a3` revalidated the decorated type, object layout, installer stores, locator/vtable bytes and slots, target-method data reachability, and source/compiler split.
- Source policy: keep the reusable declaration only in UID0001WQ; keep UID0004W2 as a concrete covered-by marker; keep UID0004W4/UID0004W5 as compiler-data markers; keep feature binding in TerminalPane.cpp. Do not duplicate the template, emit raw RTTI/vtable data, or preserve IDA/compiler labels as source names.

### NexonclubRegistrationDialog Unsigned-Long Callback Instantiation

[UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md) contains the exact compiler-data table for `PlainMemberFunctionObject<void (__thiscall NexonclubRegistrationDialog::*)(unsigned long), NexonclubRegistrationDialog>`. The reusable template source remains in UID0001WQ; the concrete binding belongs to `NexonclubRegistrationDialog::OnControlCommand`, and the physical table remains false/non-emitting.

- Complete-object-locator cell: `0x00620180 -> 0x0064cbdc`; type descriptor `0x00678298`; hierarchy descriptor `0x0064cbf0`.
- Hierarchy: concrete callback BCD `0x0064cc10`, `FunctionObject` BCD `0x0064623c`, and `LObject` BCD `0x00640348`.
- Five-slot table `[0x00620184,0x00620198)`: shared 24-byte callback scalar deleting destructor `0x0049b090`; inherited `LObject::GetRuntimeClass` `0x004f4b10`; inherited `LObject::OnChangeMessage` `0x0041b6c0`; shared one-argument invoke wrapper `0x0049af00`; and virtual object-size result `24 / 0x18` at `0x004673f0`.
- Concrete construction: `NexonclubRegistrationDialog::OnControlCommand` stores vtable `0x00620184` at `0x00530189`, stores member target `0x00530020` at `0x0053018f`, stores zero member adjustment, and captures the current dialog object in the 24-byte callback.
- Bound target: `NexonclubRegistrationDialog::OnPendingRegistrationAlertClosed(unsigned long)`. It ignores the alert result, clears pending state, cancels timer 0, destroys and nulls the pending alert, and is live through the member-function pointer even though it has no ordinary direct call xref.
- Source/compiler boundary: human source is the shared `PlainMemberFunctionObject` declaration plus the concrete `OnControlCommand` binding. The locator, RTTI hierarchy, five table dwords, folded invoke, deleting destructor, and object-size virtual are compiler/linker output and must not be copied into a standalone table definition.
- Ownership boundary: UID0003C7 remains semantically owned by [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md) but non-emitting. UID0001WQ owns reusable wrapper declarations; [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md) owns the concrete executable binding site through [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md).
- Boundary negative: the immediately preceding UID0004WH callback table ends at `0x006200a8` and has a different decorated CreateUserDialogPane const-string specialization; adjacency does not merge or reown either instantiation.

## Layout Notes

Observed callback object layouts are small and consistent:

| Field family | Meaning |
| --- | --- |
| vtable/base slots | `LObject` or function-object base metadata. |
| callback pointer | Member-function dispatch target, usually emitted as a plain adjusted function pointer in decompilation. |
| object pointer | Captured target object. |
| this adjustment | Offset applied before calling the member function. |
| captured arguments | Small bound values such as slot letters, booleans, or quantity flags. |

Concrete UserPane slot/bool instantiation details:

```cpp
typedef void (__thiscall UserPane::*UserPaneItemActionCallback)(signed char, bool);
typedef DoubleParamMemberFunctionObject0<UserPaneItemActionCallback, UserPane, signed char, bool>
    UserPaneItemActionCallbackObject;
```

For [UID:000040][DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528](by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md), field names should be `m_callback`, `m_thisAdjust`, `m_target`, `m_slot`, and `m_allItems`. [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) constructs the object, and [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) invokes `(adjustedTarget->*m_callback)(m_slot, m_allItems)`.

[UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md) stores such zero-argument callbacks through the base pointer `FunctionObject0 *m_acceptAction` at `+0x108`. The accepted-action method invokes slot `+0x0c` with no call-time arguments, while the destructor paths release slot `+0x00`; the concrete UserPane double-parameter object is still a zero-call-argument callback because the `UserPane`, slot byte, and all-items bool are captured when the object is constructed.

## Source Migration Notes

Keep the template declarations with shared callback utility code. Keep feature-specific construction sites in their feature files, because those sites know which member function and arguments are being captured.

Do not create standalone original source files from every long compiler-template instantiation name. That would mirror compiler output rather than the likely Visual C++ project structure.

For exact invoke-wrapper pages, a formal comment-only proof marker is acceptable when the wrapper is reconstructable, the vtable slot, construction stores, and bound target or object layout are proven, and the target routes through FunctionObjects to the shared source root. [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) is such a case through concrete owner/emitter [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md). [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) is the folded one-argument case: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) is the direct owner/emitter for the shared body, while popup and dialog pages remain construction/consumer support. The target formal block should contain only the generated-template marker, not a handwritten invoke body.

2026-05-25 IDA MCP follow-up: `0x004b0880` is constructed in MixItemDialog/AddMixingItemDialog quantity paths (`0x004afd62` and `0x004b0370`) and passed to `NumberInputDialog`. Its physical placement in the exchange tail is a linker/source-order boundary issue, not ExchangeAlertPane ownership.

2026-05-25 IDA MCP follow-up: older notes list a popup-menu callback `NoOp` at `0x004d0050`, but current IDA resolves that address inside `sub_4CFFB0` and not as a standalone function. Keep only `0x0049af00` as confirmed callback-wrapper code.

2026-05-26 IDA MCP follow-up: representative invoke/destructor rows still resolve as vtable/data-referenced support with no direct code callers for invoke wrappers. This remains a source-layout normalization issue rather than feature ownership evidence.

2026-05-31 IDA MCP follow-up: representative callback/template rows were rechecked with `lookup_funcs`, `callers`, `xrefs_to`, and decompilation. `0x0049af00`, `0x004671a0`, `0x004b0880`, and `0x005b77b0` decompile as tiny wrappers that call the stored member-function pointer at object offset `+8` with adjusted target pointer `*(this+12)+*(this+16)` and optional captured byte arguments. `0x0052a460` and `0x0052f780` decompile as scalar deleting destructors that reset function-object vtables, call the base destructor helper, and conditionally delete. Direct callers remain empty while vtable/data xrefs are present, confirming virtual callback-template support rather than normal free functions.

The MusicControlDialog folder-selection wrapper has been split into exact memory pages: [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md) and [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md). B001 2026-06-25 current MCP proof supersedes the older blank-block guidance for [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md): exact target pages for `PlainMemberFunctionObjectT<MusicControlDialog, String>` invoke glue may carry comment-only no-code proof when the vtable and construction route are proven. Do not emit a decompiler-shaped concrete wrapper body there; reusable source stays in the shared template declaration and the concrete binding remains in [UID:0003MD][0x00529790-0x00529b70.MusicControlDialogHandleControlCommand](by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md), which stores vtable `0x0061fcec`, target `0x00529ee0`, zero adjustment, and the `MusicControlDialog` object pointer at `0x00529842-0x00529856`.

B002 2026-06-29 current MCP proof applies the same invoke-wrapper policy to [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md): exact target pages for `PlainMemberFunctionObject0<Application>` invoke glue may carry comment-only generated-template proof when the vtable and construction route are proven. Do not emit a decompiler-shaped concrete wrapper body there; reusable source stays in the shared template declaration and the concrete binding remains in [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md), which stores vtable `0x00612e40` at `0x00464ec6`, target helper `0x00464e20` at `0x00464ecc`, zero adjustment at `0x00464ed3`, and the `Application` object pointer at `0x00464eda`.

B008 2026-06-29 current MCP proof narrows [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) as the `PlainMemberFunctionObject0<Application>` object-size virtual: `sub_4673F0` is exactly `0x6` bytes, bytes `b8 18 00 00 00 c3`, decompiles to `return 24`, has no callees, has `0xcc` padding before/after, and is reached through fourteen data-only vtable refs including local slot `0x00612e50 -> 0x004673f0`. This supports the target-level formal comment-only proof marker and rejects a handwritten `return 24;` body. The source-level declaration remains shared `PlainMemberFunctionObject0` template support and the concrete object layout remains tied to Application construction.

B007 2026-06-29 current MCP proof narrows [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) as the `FunctionObject0` 24-byte scalar deleting destructor metadata: `sub_4671F0` is exactly `0x3e` bytes / decimal `62`, uses delete-size constant `0x18` / decimal `24`, has no code callers or code xrefs, is reached through vtable/data-only refs from the local `FunctionObject0` and `PlainMemberFunctionObject0<Application>` tables, and has endpoint/padding negatives. This supports blank formal C++ and blank `EMITTER_UIDS:` on the exact target; it does not authorize a comment-only formal marker or handwritten destructor body.

B010 2026-06-29 current MCP proof narrows [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md) as the `FunctionObject0` `0x04` guard-size scalar deleting destructor metadata: `sub_4672C0` is exactly `0x3e` bytes / decimal `62`, range endpoint `0x004672fe` is not a function, the body resets `FunctionObject0::vftable` from `0x0061262c`, calls `sub_4F4A90`, tests scalar-delete flags `1` and `4`, conditionally calls `sub_4F4AC0`, and reaches `@_guard_check_icall_nop@4` through guard size `0x04` / decimal `4`. It has one local vtable data ref, no code callers or code xrefs, no endpoint refs, no raw endpoint pointer route, and `CC` padding-separated siblings. This supports blank formal C++ and blank `EMITTER_UIDS:` on the exact target; it does not authorize a comment-only formal marker or handwritten destructor body.

B006 2026-06-27 current MCP proof narrows the adjacent generic string callback base destructor [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md): `sub_52A460` is exactly `0x3e` bytes, writes `0x0061fcd4`, calls the FunctionObjects/`LObject` cleanup path, conditionally releases storage through scalar-delete flags, has only the `0x0061fcd4` vtable data xref, no code callers/refs, no raw endpoint pointer route, and `CC CC` padding before [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md). This supports the shared template declaration route and blank formal C++ for scalar deleting destructor glue; it does not move ownership to MusicControlDialog or StringBase.

B007 2026-06-28 current MCP proof narrows the const-reference string callback base destructor pair [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md): `sub_52F780` and `sub_52F7C0` are each exactly `0x3e` bytes / decimal `62`, reset `off_61FF58`, call `sub_4F4A90`, `sub_4F4AC0`, and `@_guard_check_icall_nop@4`, use scalar deleting flag gates with delete-size immediates `4` and `0x18` / decimal `24`, have only vtable/data refs from `0x0061ff58`, `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4`, have no direct callers, and have no endpoint refs or endpoint pointer patterns. This supports the shared template declaration route and non-emitting metadata with blank formal C++ plus blank `EMITTER_UIDS:`; it does not move ownership to StringBase/StringUtil or any create-user/Nexonclub consumer.

2026-06-05 IDA MCP follow-up: [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) allocates and initializes the `UserPane` double-parameter callback object, stores vtable `0x00630a78`, callback pointer, adjusted object fields, slot byte, and bool flag. [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) is the corresponding vtable invoke slot at `0x00630a84`.

2026-06-20 B003 Rule 26 follow-up: the `UserPane` double-parameter callback target methods are now behaviorally resolved as `UserPane::SendDropItemPacket(signed char,bool)` at `0x005ad7a0` and `UserPane::SendGiveItemPacket(signed char,bool)` at `0x005ad720`; [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) is a concrete out-of-line factory/new helper for `UserPaneItemActionCallbackObject`. Exact original template header spelling remains open, but the concrete owner/emitter and source-equivalent behavior are no longer blockers.

2026-06-22 B014 Rule 26 verification: B014 reconfirmed the exact [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) body as compiler-emitted `DoubleParamMemberFunctionObject0<UserPane, signed char, bool>::Invoke` glue reached only through vtable slot `0x00630a84`. Keep its target-level formal block as generated-binary proof/comment-only; do not emit a decompiler-shaped standalone method body there.

2026-06-12 IDA MCP follow-up: [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md) is the concrete proxy-dialog const-string callback wrapper. The `NexonclubProxyDialog` constructor allocates 24 bytes, stores vtable `0x00622cf4` at `0x0055388f`, stores member target `0x005534a0`, zero adjustment, and the bound proxy object, then passes the wrapper to `NexonclubRegistrationDialog`.

2026-06-13 B001-000123 follow-up: [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) is the shared 24-byte callback-template scalar deleting destructor support used by multiple concrete callback vtables. It is not the base `FunctionObject::vftable` destructor.

2026-06-13 B001-0003LP follow-up: [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md) is the base `FunctionObject::vftable` scalar deleting destructor routed through [UID:00005K][FunctionObject](by-class/FunctionObject.md). IDA confirms the `FunctionObject` RTTI/vtable slot and two `__purecall` abstract slots, while the final template/header spelling remains open.

2026-06-16 C001 live IDA refresh: active database `NexusTK.exe.i64` in session `b001_selflookpane_0001H7_20260616` reconfirmed the representative callback/template support as real IDA functions with the documented sizes: `0x0049af00` `0x11`, `0x0049b090` `0x3e`, `0x0049b250` `0x3e`, `0x004671a0` `0x0d`, `0x004671f0` `0x3e`, `0x004672c0` `0x3e`, `0x004673f0` `0x06`, `0x004b0880` `0x21`, `0x0052a3e0` `0x5e`, `0x0052a4a0` `0x3e`, `0x0052a460` `0x3e`, `0x005b7450` `0x8d`, and `0x005b77b0` `0x18`. `xrefs_to` still shows vtable/data refs for the virtual invoke/destructor slots (`0x0049af00` seven data refs, `0x0049b090` four data refs, `0x0049b250` one base-vtable data ref, `0x004671a0` four data refs, `0x004b0880` one data ref, `0x0052a3e0`/`0x0052a4a0` one data ref each, and `0x005b77b0` one vtable data ref), while `0x005b7450` has the four live UserPane construction callers. Decompilation still shows the same ABI pattern: stored member-function pointer at object `+0x08`, adjusted object pointer from `+0x0c/+0x10`, optional captured byte arguments at `+0x14/+0x15`, and 24-byte callback object allocation for the UserPane factory. Safe IDA labels were applied and saved for the documented invoke/destructor/factory helpers. Skipped IDA edits: no type/member/prototype edits and no final template declaration were entered, because the original header basename, exact template family spelling, and whether some emitted destructors collapse to one source declaration remain source-heuristic rather than binary-proven. B-agent escalation is recommended only for final original template/header reconstruction, not for the already-supported ownership route.

2026-06-17 B002 source-quality follow-up: [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md) uses the same shared callback family for alert results. The constructor stores a 24-byte function-object pointer at `VersatileAlertPane::m_resultCallback` (`+0x270`), accept/cancel invoke callback slot `+0x0c` with unsigned-long values `1/0`, and cleanup/destructor paths release the callback through slot `+0x00`.

## 2026-06-29 Empty-Emitter Closeout

Agent-B013 selected this page as the central reusable source-declaration carrier for the FunctionObjects family. `EMITTER_POSITION_OPTIONAL:0` keeps the declaration block before concrete markers in `auto-generated/NexusTK/util/FunctionObjects.cpp`.

The formal block above is intentionally the only reusable declaration emitted for the family. Concrete instantiation pages carry covered-by markers rather than duplicate declarations. The source route is:

- UID0001WQ emits shared declarations for `FunctionObject`, `FunctionObject0`, `FunctionObjectT`, `PlainMemberFunctionObject0`, `PlainMemberFunctionObject`, `PlainMemberFunctionObjectT`, `DoubleParamMemberFunctionObject0`, and `DoubleParamMemberFunctionObject`.
- UID0002VM emits the source-equivalent UserPane double-param callback allocation and binding factory.
- UID0001N5, UID00014W, UID000324, UID00032C, UID00011X, and UID0002N2 remain filled generated markers for concrete invoke/object-size helpers.
- UID0002YW, UID0003DF, UID000482, UID0003OE, UID000486, and UID0003OF carry no-raw-vtable or no-raw-RTTI markers because those ranges are generated from declarations and construction sites.
- UID000123, UID0001CQ, and UID0002N3 remain blank-formal non-emitting scalar deleting destructor glue; their `EMITTER_UIDS` are blank unless a later supervisor explicitly changes the scalar-destructor policy.

Current MCP evidence supporting this source placement: `0x005b7450` allocates the 24-byte UserPane callback object and stores vtable `0x00630a78`; `0x00630a78` carries the decorated `DoubleParamMemberFunctionObject0<UserPane, signed char, bool>` vtable name; `0x00622cf4` carries the decorated `PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBase&>` vtable name; `0x0061262c` and `0x00612e40` are compiler-emitted vtables for FunctionObject0 and PlainMemberFunctionObject0<Application>; and scalar deleting destructors at `0x0049b090`, `0x0052a460`, and `0x0052a4a0` are 0x3e-byte compiler glue with vtable-data refs only.

This closes the generated empty-emitter blocker for the shared declaration route, but exact original header spelling, typedef ordering, include placement, and MSVC pointer-to-member layout details remain below final-source certainty.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page now has current live IDA coverage for representative invoke wrappers, base and template scalar deleting destructors, UserPane factory/invoke pair, MusicControlDialog callback pair, Application callback bodies, vtable/data xrefs, owner/emitter route through [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), and the central formal declaration block. |
| Confidence | 90 | Callback-object behavior, construction use, and shared `FunctionObjects` ownership are strongly supported by decompilation, exact by-memory children, vtable refs, saved IDA labels, and current MCP evidence. Confidence stays below final-audit levels because exact original header spelling, typedef ordering, include placement, and some template parameter spelling remain inferred rather than directly recovered. |
| Parent | `0000JO` | [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) already clears the strict parent gate and remains the direct reusable callback utility owner; feature construction sites stay with their feature modules. |

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001Q9][client_callback_dispatch](by-meta/client_callback_dispatch.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)
- [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md)
- [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md)
- [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md)
- [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md)
- [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md)
- [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md)
- [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md)
- [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- [UID:0004W2][PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_](by-class/PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_.md)
- [UID:0004W4][0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer](by-memory/0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer.md)
- [UID:0004W5][0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData](by-memory/0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData.md)
- [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)

## 2026-08-11 UID0001CU Implementation Callback

- Current metadata remains `88/90`; owner/emitter remain [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), reconstructable remains true, position remains `0`, and `Nested:0` remains exact.
- The complete reusable callback-template family moved from the formal CPP channel to the formal H channel without dropping or rewriting any class, constructor, invocation path, adjustment field, object pointer, bound argument, or object-size method.
- The formal H now owns `#pragma once`, `LObject.h`, `FunctionObject`, `FunctionObject0`, `FunctionObjectT`, `PlainMemberFunctionObject0`, `PlainMemberFunctionObject`, `PlainMemberFunctionObjectT`, `DoubleParamMemberFunctionObject0`, and `DoubleParamMemberFunctionObject`. The formal CPP is exactly the self-header include.
- UID0001CU and the three create-user provider paths instantiate these shared templates at their source sites. No registration-specific alias, member function, concrete callback vtable, or RTTI data moved into this shared template page.

## Changes

- 2026-08-17 B008 UID000482 source-quality callback:
  - Preserved `88/90` and the complete formal CPP/H declaration family.
  - Added exact proof that the existing `FunctionObject0 : public LObject` declaration regenerates UID000482's two-base RTTI locator chain and UID0003OE's five-slot primary vtable, while keeping raw RTTI/vtable storage and scalar deleting-destructor bodies out of authored source.

- 2026-07-30 B002 UID0003P4 BaramApp specialization integration:
  - Preserved `88/90`, owner/emitter metadata, and the existing shared formal template declarations.
  - Added the concrete `PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>` instantiation, exact 24-byte layout, five vtable slots, RTTI/COL child, and sole Application startup construction route.
  - Recorded the source split: reusable declaration in `util/FunctionObjects.h`; private member declaration in `app/Application.h`; concrete body/binding in `app/Application.cpp`; compiler-generated table on UID0003P4.
  - Preserved the no-raw-table, no-handwritten-invoke/object-size/deleting-destructor policy and feature ownership boundary.

- 2026-07-26 B005 UID0003C7 callback incorporation:
  - Preserved current UID0001WQ metadata, formal template declarations, central source route, and all existing instantiation evidence.
  - Added the exact NexonclubRegistrationDialog unsigned-long specialization, locator/hierarchy, five table slots, 24-byte construction stores, bound `OnPendingRegistrationAlertClosed` target, and class/template/executable ownership split.
  - Kept the concrete table false/non-emitting and rejected raw RTTI/vtable output or a duplicated feature-local template declaration.

- 2026-07-22 B003 UID00046O callback implementation sync:
  - Preserved score `88/90`, the shared template declarations, existing instantiation evidence, and the FunctionObjects source route.
  - Added the concrete three-parameter `CreateUserDialogPane` const-wide-string callback instantiation, exact 24-byte field layout, construction stores, member target UID00046P, ownership handoff, and non-emitting compiler-data child UID0004WH.
  - Kept the source/compiler boundary explicit: human source is the shared template plus UID00046O construction; RTTI, vtable slots, deleting-destructor glue, folded invoke code, and object-size output are regenerated rather than handwritten.

- 2026-07-22 B001 UID0003GT source-quality callback:
  - Preserved score `88/89`, central managed template declarations, ownership/emitter route, and all unrelated instantiation evidence.
  - Added the exact UID0004W2 TerminalPane unsigned-long callback row, 24-byte layout/construction binding, compiler locator/vtable children UID0004W4/UID0004W5, shared UID00011X/UID000123 support, and healthy MCP evidence.
  - Kept the reusable declaration single-sourced here while rejecting duplicate concrete declarations and raw compiler-data source.

- 2026-06-29 B010 [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) implementation sync:
  - Score unchanged.
  - Added UID00011X to the accepted invoke-wrapper policy as the shared one-argument `PlainMemberFunctionObject` / `PlainMemberFunctionObjectT` example, with current MCP session `279422f0` proof for exact `0x11` / 17-byte body, byte signature, field offsets `+0x08/+0x0c/+0x10`, no direct callees/callers, seven vtable slots, seven concrete vtable names, and construction stores.
  - Clarified that the reusable source remains the shared FunctionObjects template declaration; popup, NewUser/CreateUser, Nexonclub, and TerminalPane pages are construction/consumer contexts. Preserved scalar deleting destructor blank-formal policy as separate from invoke/object-size markers.

- 2026-06-29 B012 [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) implementation sync:
  - Score unchanged at `85/89`.
  - Added the MixItemDialog `DoubleParamMemberFunctionObject` invoke-wrapper case to the accepted target-level comment-only generated-template marker policy.
  - Recorded current MCP session `c9671f69` proof for exact size/bytes/signature, no direct code callers, vtable slot `0x0061a3bc -> 0x004b0880`, construction stores `0x004afd62/0x004afd68` and `0x004b0370/0x004b0376`, and bound callback target [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md).
  - Clarified that exact wrapper pages may emit comment-only proof markers when vtable, construction stores, and bound target are proven; scalar deleting destructor pages remain separate blank-formal-C++ policy cases.

- 2026-06-29 B010 [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md) implementation sync:
  - Score unchanged at `85/89`.
  - Added UID000328 as the `FunctionObject0` `0x04` guard-size scalar deleting destructor example under the scalar deleting destructor no-code policy.
  - Added current MCP session `c9671f69` proof: exact `0x3e` / decimal `62` range, local `FunctionObject0::vftable` data ref at `0x0061262c`, no code callers/refs, endpoint negatives, and padding-separated boundaries. Preserved comment-only formal markers for proven invoke/object-size wrappers only.

- 2026-06-29 B007 [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) implementation sync:
  - Score unchanged at `85/89`.
  - Added the `FunctionObject0` 24-byte scalar deleting destructor as an explicit scalar-destructor policy example with current MCP session `d4d50b81` proof.
  - Clarified that UID000327 remains non-emitting with blank formal C++ and blank `EMITTER_UIDS:`, while UID000324/UID00032C remain separate target-level invoke/object-size generated-binary marker cases.

- 2026-06-29 B008 [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) implementation sync:
  - Score unchanged at `85/89`.
  - Merged the Application object-size virtual into the B002 UID000324 target-level generated-template marker policy.
  - Added current B008 MCP proof for the `0x18` object-size virtual and rejected a handwritten `return 24;` target body.

- 2026-06-29 B002 [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) implementation sync:
  - Score unchanged at `85/89`.
  - Added the `PlainMemberFunctionObject0<Application>` invoke-wrapper policy: [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) may carry target-level comment-only generated-template proof, while reusable source remains in the shared template declaration and the concrete binding stays at [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md). This policy remains distinct from scalar deleting destructor no-code handling.

- 2026-06-28 B007 [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added the current MCP session `b009_0001Q4_20260628` proof for the const-reference string callback scalar deleting destructor pair and clarified that scalar deleting destructor metadata pages with blank formal C++ should clear `EMITTER_UIDS:` unless a supervisor-approved nonblank formal marker exists. [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) remains FunctionObjects template support, not StringBase/StringUtil or feature-dialog source.
- 2026-06-27 B006 [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added the scalar deleting destructor policy and current MCP session `398b87c1` proof for the generic string-argument `FunctionObjectT` destructor. The exact target remains source-declared/generated-binary with blank formal C++ because the shared template declaration should regenerate the emitted destructor body; comment-only formal C++ remains for proven invoke wrappers, not scalar deleting destructor glue.
- 2026-06-25 B001 0002N2 source-quality implementation:
  - Score unchanged at `85/89`.
  - Added the `PlainMemberFunctionObjectT<MusicControlDialog, String>` invoke-wrapper policy: [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md) may carry target-level comment-only no-code proof, while reusable source remains in the shared template declaration and the concrete binding stays at the MusicControlDialog construction site.
- 2026-05-31 scoring/rebuild update:
  - What existed before: the page was scored `0/0`, had blank reconstructable metadata, and referenced the MusicControlDialog callback wrapper only by raw addresses.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, with the MusicControlDialog invoke/destructor split into exact by-memory pages and linked by UID.
  - Summary/evidence: IDA MCP `lookup_funcs`, `callers`, `xrefs_to`, and decompilation confirm representative function-object wrappers as vtable/data-referenced callback-template code; the page still stays below `95+` because the exact original template declaration names, all construction sites, and final source emission shape are not fully audited.
- 2026-06-05 UserPane callback refresh:
  - Before: the page had no parent attachment, still cited stale provenance paths, and listed the `UserPane` instantiation only by invoke address.
  - After: raised to `82/88`, attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), removed stale provenance, and linked both the construction helper and invoke body for the `UserPane` double-parameter instantiation.
  - Evidence: current IDA MCP confirms the `0x005b7450-0x005b74dd` construction helper, `0x005b77b0-0x005b77c8` invoke body, vtable slot `0x00630a84`, and four drop/give construction callers.
- 2026-06-16 C001 type/template refresh:
  - Before: the page was `82/88` and still relied on older representative callback checks for the source-quality blockers.
  - After: raised to `85/89`, recorded current live IDA function sizes, xref classes, decompilation patterns, safe IDA labels, and the remaining final-template/header blocker.
  - Evidence: `lookup_funcs`, `xrefs_to`, and decompilation in session `b001_selflookpane_0001H7_20260616` reconfirmed the callback ABI and ownership route; `rename` dry-run accepted 13 FunctionObject helper labels and `idb_save` succeeded. Final C++ remains blank because original template declarations and source-header spelling are still heavy heuristic work.
- 2026-06-17 B002 VersatileAlertPane callback refresh:
  - Score unchanged at `85/89`.
  - Added the alert-result callback use as a known shared `FunctionObjectT<unsigned long>` direction, while keeping exact template spelling below the final-source gate.
- 2026-06-20 B003 UserPane callback Rule 26 incorporation:
  - Score unchanged at `85/89`.
  - Added the `UserPaneItemActionCallbackObject` alias, field-name guidance, source-equivalent invoke expression, and resolved drop/give packet callback target behaviors.
- 2026-06-21 B009 ConfirmInputPane callback incorporation:
  - Score unchanged at `85/89`.
  - Added `ConfirmInputPane::m_acceptAction` as a `FunctionObject0` base-pointer consumer of the same UserPane double-parameter callback object, documenting the constructor store, accepted-action invoke slot, and destructor release route.
- 2026-06-22 B014 UserPane double-param callback verification:
  - Score unchanged at `85/89`.
  - Added a source-facing `DoubleParamMemberFunctionObject0` declaration draft and recorded that [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) should remain generated-template proof/comment-only at target level.
