*** UID:0000FU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class VersatileAlertPane : public AlertPane
{
public:
    VersatileAlertPane(const wchar_t *messageText,
                       Pane *layoutReference,
                       FunctionObjectT<unsigned long> *resultCallback,
                       const wchar_t *primaryButtonText,
                       const wchar_t *secondaryButtonText);
    virtual ~VersatileAlertPane();

protected:
    virtual void OnPrimaryButton();
    virtual void OnSecondaryButton();

private:
    FunctionObjectT<unsigned long> *m_resultCallback;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# VersatileAlertPane

## Status

- Likely source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- Source-method index and children: [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md), constructor [UID:0004NB][0x004a0690-0x004a06d7.VersatileAlertPaneConstructor](by-memory/0x004a0690-0x004a06d7.VersatileAlertPaneConstructor.md), ordinary destructor [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md), primary callback [UID:0004NC][0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton](by-memory/0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton.md), and secondary callback [UID:0004ND][0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton](by-memory/0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton.md).
- Compiler-destructor comparison range: [UID:000130][0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland](by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md). Its ABI split is B004-owned and is not emitted as handwritten source by this class.
- Vtables: [UID:0001Z0][VersatileAlertPaneVtables](by-type/by-vtable/VersatileAlertPaneVtables.md) at `0x00618ba4`, `0x00618c0c`, and `0x00618c3c`.
- Layout docs: [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md), with `m_resultCallback` at `+0x270`.
- Current recovered file: `source-3/simroot_v2/class_VersatileAlertPane.cpp`
- Confidence: very strong for behavior, vtable ownership, field role, exact shared callback type/member call, method boundaries, and source family; the exact original file basename remains inferred.
- Autogen status: reconstructable class shell parented to [UID:0000HE][AlertPanes](by-file/AlertPanes.md). The class closes before `[[CHILDREN]]`, so its four exact by-memory source-method children emit legal file-scope definitions. UID00012X remains a non-emitting semantic index.

## Class Purpose

`VersatileAlertPane` is a thin `AlertPane` subclass that reports accept/cancel results through a stored shared `FunctionObject`-style callback object. It is a generic prompt wrapper rather than a feature-specific dialog.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `VersatileAlertPane` | [UID:0004NB][0x004a0690-0x004a06d7.VersatileAlertPaneConstructor](by-memory/0x004a0690-0x004a06d7.VersatileAlertPaneConstructor.md) | Calls `AlertPane::AlertPane`, stores the owned `m_resultCallback` at `+0x270`, and installs three `VersatileAlertPane` vtables. |
| `~VersatileAlertPane` | [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md) | Unique ordinary source destructor: `delete m_resultCallback;`. Compiler vptr resets and base teardown are not handwritten. IDA does not model this copy as a function and reports no callers; that negative evidence is retained. |
| `OnPrimaryButton` | [UID:0004NC][0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton](by-memory/0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton.md) | Accept/primary behavior alias formerly documented as `OnAccept`; invokes `m_resultCallback->Invoke(1)` when non-null. |
| `OnSecondaryButton` | [UID:0004ND][0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton](by-memory/0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton.md) | Cancel/secondary behavior alias formerly documented as `OnCancel`; invokes `m_resultCallback->Invoke(0)` when non-null. |
| `AdjustorThunk` | `0x004a0cb0-0x004a0ccb` | Secondary/tertiary vtable adjustor thunks into the deleting destructor. |
| `ScalarDeletingDestructor` | `0x004a0cd0-0x004a0d37` | Releases `m_resultCallback` through the shared `FunctionObject` destructor slot, tears down the alert base, and optionally deletes storage. |

## Evidence Notes

- IDA decompilation of `0x004a0690` directly calls `0x0049feb0`, stores the callback/control value at object offset `0x270`, and patches all three vtables.
- 2026-05-26 IDA MCP vtable pass confirms `VersatileAlertPane` primary/secondary/tertiary vtables at `0x00618ba4`, `0x00618c0c`, and `0x00618c3c`, installed by constructor stores at `0x004a06b6`, `0x004a06bc`, and `0x004a06c6`.
- 2026-05-26 IDA layout pass confirms constructor store and cleanup/destructor reads of the callback pointer at `+0x270`; see [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- The primary table overrides `AlertPane` callback extension slots `+0x5c` and `+0x60` with `OnPrimaryButton` and `OnSecondaryButton`; most drawing and dialog slots remain inherited. `OnAccept` and `OnCancel` are behavior aliases only unless the base `AlertPane` declaration is renamed project-wide.
- IDA raw disassembly shows `0x004a06e0-0x004a0715` as unreferenced cleanup-shaped code, not currently an IDA function. It has no `xrefs_to 0x004a06e0`, but vtable-store xrefs land at `0x004a06e9`, `0x004a06ef`, and `0x004a06f9`; fresh 2026-06-13 byte review shows the corrected half-open end is `0x004a0715` because `0x004a0714` is the final byte of the base-teardown jump immediate.
- 2026-06-13 IDA MCP recheck confirms constructor callers at `0x005301de` and `0x0058b5c5`, accept/cancel vtable-data refs at `0x00618c00` and `0x00618c04`, adjustor-thunk vtable refs at `0x00618c0c` and `0x00618c3c`, and deleting-destructor refs from both adjustor thunks plus the primary vtable.
- 2026-06-13 `analyze_function` confirms the constructor writes the callback/control pointer to `this[156]` / offset `+0x270` (624 bytes, Verified with int_convert.py), `OnPrimaryButton` / accept behavior calls callback slot `+0x0c` (12 bytes, Verified with int_convert.py) with result `1`, `OnSecondaryButton` / cancel behavior calls the same slot with result `0`, and the deleting destructor releases the callback through slot `0`, calls the shared alert base teardown, and conditionally frees object storage.
- 2026-06-17 B002 source-quality recheck names the `+0x270` field `m_resultCallback`. Best type direction is the shared `FunctionObjectT<unsigned long>*` family, or conservative `FunctionObject*` until final callback-template declarations are coordinated. The two known constructor callers allocate 24-byte `PlainMemberFunctionObject`-style callback objects; this rejects a pane-local `IVersatileAlertPaneCallback` interface and rejects flag/control interpretations for the field.
- The best constructor signature direction is `VersatileAlertPane(const wchar_t *messageText, Pane *layoutReference, FunctionObjectT<unsigned long> *resultCallback, const wchar_t *primaryButtonText, const wchar_t *secondaryButtonText)`: the constructor forwards the four non-callback arguments to `AlertPane::AlertPane`, stores the non-forwarded callback argument at `+0x270`, and uses that field from both result handlers and cleanup/destructor paths.
- 2026-06-25 B008 MCP/PE recheck preserves this class as the direct owner/emitter for [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md): current evidence still finds no IDA function, no MCP xrefs/code-only xrefs, no direct VA/RVA pointer hits, and no filtered `.text` rel32 route to `0x004a06e0`, while the raw body still writes this class's three vtable views, releases `m_resultCallback`, and tail-jumps to shared alert/DialogPane teardown. Keep the class C++ declaration-only here; final executable source should coordinate one `virtual ~VersatileAlertPane()` destructor body through the method/destructor children, not add a separate raw-cleanup helper or public destructor body at [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md).
- IDA xrefs to the constructor include calls from `0x005301de` and `0x0058b5c5`.
- `0x004a0760` is `ModelessDialogPane` construction and should not be treated as `VersatileAlertPane` despite address locality.

## Current Source-Quality Resolution - 2026-07-14

- `VersatileAlertPane` is exactly `0x274` bytes: the `AlertPane` base is `0x270` bytes and the sole derived field is the owned `FunctionObjectT<unsigned long> *m_resultCallback` at `+0x270`.
- The constructor's five source arguments are fixed by push/store order: message text, layout reference, callback, primary label, and secondary label. It forwards the four non-callback values to `AlertPane`, then stores the callback.
- Current [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) supplies the compile-visible `FunctionObjectT<unsigned long>::Invoke(unsigned long)` contract. The two caller-created 24-byte member-function callback objects and the callback slot calls resolve the previously conservative `FunctionObject*`/unknown-member wording.
- The primary and secondary tables override the base slots with `OnPrimaryButton` and `OnSecondaryButton`; each method has one null branch and one exact unsigned-long result, respectively `1` and `0`.
- The ordinary destructor is the source-bearing ownership release. The adjusted destructor entries, scalar deleting wrapper, vptr writes, base teardown, delete flags, and vtable/layout bytes remain compiler consequences and must not be handwritten in this declaration or its source children.
- RTTI/vtable evidence fixes three class views at `0x00618ba4`, `0x00618c0c`, and `0x00618c3c`, complete-object locator offsets `0`, `0xa0`, and `0xa4`, and the eight-entry hierarchy shared with `AlertPane`/`DialogPane` bases.
- The previous declaration-only/deferred-call conclusion is preserved below as evidence-time history. It is superseded by the exact child bodies and current shared template declaration.

## Data Caveats

- Evidence-time generated source contained a stray `BackGroundPane` deleting-destructor typedef and labeled the base teardown as `TransferReplyAlert::~TransferReplyAlert`. Those were owner/type pollution, not accepted source declarations.
- The earlier uncertainty between `FunctionObjectT<unsigned long>*`, conservative `FunctionObject*`, and a local alias is resolved in favor of the compile-visible shared `FunctionObjectT<unsigned long>*` declaration. A pane-local callback interface remains rejected by both caller allocations and shared template evidence.
- Final source should emit one constructor, two no-argument primary/secondary button overrides, and one virtual destructor. It should not hand-write raw cleanup, scalar deleting wrapper, secondary/tertiary adjustor thunks, or vtable dword arrays as ordinary source methods.

## First-Draft Declaration Notes

The class declaration above is source-ready enough for class/vtable shape and matches mid-2000s C++ style by avoiding C++11 `override`. It deliberately uses the shared `FunctionObjectT<unsigned long>*` type direction already documented by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md); if final header work chooses an `AlertResultCallback` alias, only that spelling should change.

Historical note: method bodies were previously deferred to the aggregate and compiler-destructor pages while the exact callback call spelling remained unresolved. The accepted source route now emits from UID0004NB, UID00012Y, UID0004NC, and UID0004ND, using the current `Invoke` contract. UID00012X and UID000130 are indexes/evidence rather than duplicate source bodies.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md)
- [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md)
- [UID:0004NB][0x004a0690-0x004a06d7.VersatileAlertPaneConstructor](by-memory/0x004a0690-0x004a06d7.VersatileAlertPaneConstructor.md)
- [UID:0004NC][0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton](by-memory/0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton.md)
- [UID:0004ND][0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton](by-memory/0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton.md)
- [UID:000130][0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland](by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md)
- [UID:0001Z0][VersatileAlertPaneVtables](by-type/by-vtable/VersatileAlertPaneVtables.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)

## 2026-08-11 UID0001CU Formal-Route Incorporation

- Metadata remains `93/96`; owner/emitter remain [UID:0000HE][AlertPanes](by-file/AlertPanes.md), reconstructable remains true, position remains blank, and `Nested:0` remains exact.
- The complete VersatileAlertPane declaration moved from CPP into the shared AlertPanes H stream after UID00000B's preamble and closed AlertPane declaration. It intentionally contributes no second guard or include preamble.
- CPP is exactly `[[CHILDREN]]`; UID00000B owns the sole `AlertPanes.h` include. Constructor/destructor, primary/secondary handlers, and the owned unsigned-long callback member remain complete and unchanged.

## Changes

- 2026-07-14 B002 method-island callback:
  - Raised `88/90` to `93/96` after resolving the exact callback template/member contract, five-argument constructor, owned `+0x270` field, four source-bearing methods, callers, class size, RTTI/vtable views, and source/compiler split.
  - Moved `[[CHILDREN]]` after the class closing brace and registered exact method children UID0004NB, UID00012Y, UID0004NC, and UID0004ND so generated definitions are at file scope.
  - Historicalized the former declaration-only/API-deferred state. Compiler destructor ABI, vtable, and layout pages remain non-source comparison evidence owned by the coordinated B004 phase.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the constructor/callback/cleanup/destructor/thunk behavior, vtable and layout evidence, constructor xrefs, raw cleanup caveat, and generated type/owner pollution notes.
- 2026-06-13 Goal 2 parent-gate refresh:
  - What existed before: `COMPLETION:86` and `CONFIDENCE:82`; the class was the target's direct parent but did not clear the strict 85/85 parent confidence gate.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:86`.
  - Summary/evidence: fresh IDA MCP rechecked constructor/callback/destructor behavior, constructor callers, vtable-slot refs, adjustor-thunk refs, callback offset `+0x270`, callback slot `+0x0c`, and the corrected raw cleanup half-open range [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md). Final class C++ remains blank because the callback interface name, alert base teardown name, and raw cleanup source representation remain below the final-source gate.
- 2026-06-17 B002 source-quality execution:
  - Score unchanged at `86/86`.
  - Clarified `m_resultCallback` at `+0x270`, the shared `FunctionObjectT<unsigned long>` type direction, accept/cancel result values `1/0`, constructor forwarding, raw-cleanup/destructor sibling treatment, and vtable-only reachability.
  - Final C++ remains blank because the source should eventually emit one constructor, two virtual callback overrides, and one destructor shape after `AlertPane` and `FunctionObjects` declarations are coordinated, not duplicate raw cleanup and scalar-deleting wrapper bodies.
- 2026-06-21 B005 source-quality Rule 26 incorporation:
  - Raised from `86/86` to `88/90` and added declaration-only draft C++ for the class shape.
  - Changed final callback names from `OnAccept`/`OnCancel` to `OnPrimaryButton`/`OnSecondaryButton` to match [UID:00000B][AlertPane](by-class/AlertPane.md), while preserving accept/cancel as behavior aliases.
  - Recorded constructor argument order, `FunctionObjectT<unsigned long>*` callback direction, rejection of pane-local callback interfaces, and one-source-destructor policy for raw cleanup/scalar-deleting/thunk compiler artifacts.
- 2026-06-25 B008 implementation callback:
  - Score, owner/emitter, and declaration-only class C++ unchanged.
  - Added current no-entry raw-cleanup evidence for [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md), preserving the class route through [UID:0000HE][AlertPanes](by-file/AlertPanes.md) and the one-source-destructor policy.
