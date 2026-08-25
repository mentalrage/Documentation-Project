*** UID:0004W2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane> instantiation.
// The reusable declaration is emitted by UID0001WQ FunctionObjectTemplates; TerminalPane source owns the concrete binding to OnReconnectOrLeave.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PlainMemberFunctionObject void TerminalPane unsigned long TerminalPane

## Status

- Completion/confidence: `91/94`.
- Direct semantic owner and emitter: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
- Reconstructable disposition: true through a marker-only concrete-instantiation record; the reusable template declaration remains solely on [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md).
- Feature construction context: [UID:0000EG][TerminalPane](by-class/TerminalPane.md) and [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md).
- Bound source method: [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md).

## Exact Type And Layout

- Decorated RTTI/vtable names resolve the concrete type as `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>`.
- The allocated callback object is exactly 24 bytes.
- The stored member-function target occupies the callback field beginning at `+0x08` and is `TerminalPane::OnReconnectOrLeave(unsigned long)` at `0x0058b620`.
- The `this` adjustment field at `+0x0c` is zero for this binding.
- The bound `TerminalPane *` receiver occupies `+0x10`.
- The exact type has compiler RTTI locator-pointer evidence at `[0x0062dde4,0x0062dde8)` and a five-slot vtable at `[0x0062dde8,0x0062ddfc)`.

## Construction And Liveness

- [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) OnTimer code at `0x0058b470` allocates 24 bytes and writes this concrete vtable at `0x0058b567`.
- The same construction sequence stores target `0x0058b620`, zero adjustment, and the adjusted `TerminalPane` receiver.
- The vtable address has exactly one installer xref, at `0x0058b567`.
- The bound method has one data reference from the member-function store and no ordinary direct code reference, which is expected for callback-only dispatch.

## Vtable And Shared Support

| Slot | Address | Target | Disposition |
| --- | --- | --- | --- |
| 0 | `0x0062dde8` | `0x0049b090` | Shared 24-byte callback scalar deleting destructor; compiler/template support, not a TerminalPane body. |
| 1 | `0x0062ddec` | `0x004f4b10` | Shared FunctionObjects support virtual. |
| 2 | `0x0062ddf0` | `0x0041b6c0` | Shared no-op virtual. |
| 3 | `0x0062ddf4` | `0x0049af00` | Folded one-argument member invoke wrapper already documented by UID00011X. |
| 4 | `0x0062ddf8` | `0x004673f0` | Shared object-size helper returning 24. |

The scalar-destructor slot is already documented by [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md), and the invoke slot is already documented by [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md). Those folded helpers remain shared support and are not duplicated here.

## Ownership And Source Placement

- FunctionObjects owns the reusable template declaration and concrete-instantiation documentation route.
- TerminalPane owns the feature-side construction site and `OnReconnectOrLeave` source method.
- The RTTI locator pointer and vtable are compiler-generated consequences of those declarations and uses.
- No standalone generated-name source file, TerminalPane data file, handwritten RTTI array, handwritten vtable array, explicit vptr field, or explicit scalar-wrapper body is warranted.
- Generated placement remains `NexusTK/util/FunctionObjects.cpp` through UID0000JO; the feature binding remains in `NexusTK/login/TerminalPane.cpp`.

## Compiler-Data Children

- `by-memory/0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer.md`: exact complete-object-locator pointer, to be linked by its validator-issued UID after registration.
- `by-memory/0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData.md`: exact five-slot vtable, to be linked by its validator-issued UID after registration.

## Negative Evidence And Rejected Alternatives

- There is no source-authored raw pointer or dword table at these addresses.
- No evidence assigns reusable callback ABI mechanics exclusively to TerminalPane.
- No evidence assigns TerminalPane modem/parser literals to FunctionObjects.
- Explicit wrapper bodies would duplicate folded compiler/template output already shared by unrelated callback instantiations.
- The exact original header basename and template-instantiation translation-unit placement are stripped; the existing FunctionObjects route is the project-consistent source reconstruction.

## Score Rationale

- Completion `91`: the concrete type, 24-byte layout, constructor store, bound receiver/method, vtable slots, RTTI/vtable children, source route, and compiler/source boundary are complete.
- Confidence `94`: decorated names, bytes, xrefs, construction stores, and shared helper precedents converge. The score remains below 95 only because original lexical/header placement is unavailable.

## Historical / Superseded Assumptions

- Superseded: the complete callback data range was broadly TerminalPane-owned. TerminalPane remains consumer/binding context, while this concrete FunctionObjects instantiation owns the generated ABI evidence.
- Superseded: a blank mixed data page was sufficient. The concrete instantiation now provides the exact owner/emitter route without duplicating template declarations or raw ABI data.
