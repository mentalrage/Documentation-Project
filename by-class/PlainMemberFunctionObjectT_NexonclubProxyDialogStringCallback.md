*** UID:0003GK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&> instantiation.
// The reusable declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md); the concrete vtable data is covered by [UID:0003DF][0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData](by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PlainMemberFunctionObjectT NexonclubProxyDialog String Callback

## Status

- Confidence: very strong for the concrete callback-instantiation identity, constructor site, vtable data, and bound member-function target.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support, instantiated by [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md).
- Construction site: [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md).
- Vtable data: [UID:0003DF][0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData](by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md).
- Rebuild handling: `source-declared/generated-binary`; source should declare the reusable callback template and the proxy constructor should instantiate it, while the compiler emits the concrete vtable.
- Autogen parent: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md); final C++ remains blank because exact original template/header spelling is below the `95/95` source-code gate.

## Class Purpose

This compiler-emitted callback wrapper binds the anonymous `NexonclubProxyDialog` member callback at `0x005534a0` with a `const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>&` argument. The proxy constructor allocates this 24-byte wrapper, binds it to the current proxy object, and passes it into the [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md) constructor as the registration result callback.

Source-level construction should be represented in [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md) as a normal template allocation:

`new PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(this, &NexonclubProxyDialog::OnReplyText)`

This page documents the concrete generated table/object layout that results from that source expression; it should not hand-emit a separate source body or force the long IDA template symbol into final C++.

## IDA Evidence

- Live IDA MCP on 2026-06-12 decompiled `0x00553610` and recovered the concrete vtable symbol at `0x00622cf4` as `PlainMemberFunctionObjectT<void (__thiscall NexonclubProxyDialog::*)(const mystr::StringBase<wchar_t,...>&), NexonclubProxyDialog, const mystr::StringBase<wchar_t,...>&>`.
- Focused disassembly at `0x00553870-0x005538d3` shows `sub_4F4AA0(0x18)`, base initialization through `sub_4F4A80`, the vtable store at `0x0055388f`, member-function pointer store `0x005534a0` at `+0x08`, zero `this` adjustment at `+0x0c`, bound proxy object at `+0x10`, and the callback pointer passed to `sub_52F950`.
- `xrefs_to 0x00622cf4` reports exactly one data reference at `0x0055388f` inside [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md).
- `lookup_funcs` confirms the target member callback `0x005534a0-0x00553609`, the shared invoke wrapper `0x0049af00-0x0049af11`, the const-string callback scalar deleting destructor `0x0052f7c0-0x0052f7fe`, and the 24-byte size virtual `0x004673f0-0x004673f6`.
- `xrefs_to 0x005534a0` reports the member-function pointer store at `0x00553895`, paired with the vtable store at `0x0055388f`.

## Vtable And Layout

| Address / field | Meaning | Evidence |
| --- | --- | --- |
| `0x00622cf0` | complete-object locator pointer | Starts the exact callback table child before the `DLGMSGH.EPF` successor string. |
| `0x00622cf4` | scalar deleting destructor slot | Points to `0x0052f7c0`, the `PlainMemberFunctionObjectT<..., const StringBase&>` destructor support body. |
| `0x00622cf8` | base virtual slot | Points to `0x004f4b10`, shared callback/object support. |
| `0x00622cfc` | no-op virtual slot | Points to `0x0041b6c0` / `nullsub_18`. |
| `0x00622d00` | invoke slot | Points to `0x0049af00`, which dispatches `*(this+0x08)` with adjusted target `*(this+0x0c)+*(this+0x10)`. |
| `0x00622d04` | object-size virtual | Points to `0x004673f0`, which returns `0x18` / 24 bytes. |
| callback object `+0x08` | bound member-function pointer | Constructor writes `0x005534a0`. |
| callback object `+0x0c` | this adjustment | Constructor writes `0`. |
| callback object `+0x10` | bound object pointer | Constructor writes the current `NexonclubProxyDialog` pointer. |

## Ownership Boundaries

| Candidate owner | Decision | Evidence |
| --- | --- | --- |
| [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) | Source-family parent for reusable template declarations. | Existing FunctionObjects and callback-dispatch docs route reusable function-object templates here. |
| [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md) | Consumer and bound target object. | The proxy constructor creates this object and stores the proxy member callback plus bound `this` pointer. |
| [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md) | Receiver of the callback object only. | The proxy constructor passes the completed callback pointer to the registration constructor, but registration code does not own this vtable. |
| Long generated template class file | Rejected as a standalone original source root. | The long symbol is compiler-template metadata; final source should use shared template declarations plus feature construction code. |

## B008 Source-Link Refresh

The accepted B008 2026-06-26 implementation keeps this page at `86/91` and adds no formal C++. The new constructor/callback pages now use `NexonclubProxyDialog::OnReplyText` as the source-facing member name and place the draft source code in [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md) and [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md). The reusable template declaration remains with [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), while this concrete page remains evidence for the vtable/object fields emitted by the compiler.

## Assignment Gate

This concrete callback-instantiation page is the direct class parent for [UID:0003DF][0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData](by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md). It clears the strict parent gate at `86/91`, and [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) already clears the source-family parent gate at `87/85`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page records the concrete template identity, construction site, bound member target, exact vtable child, slot layout, object-field stores, owner/consumer boundaries, and rebuild handling. It remains below higher completion because final original template names and complete header/source declaration shape are still not source-final. |
| Confidence | 91 | The vtable symbol, sole vtable-base xref, member-function pointer xref, object layout stores, and shared slot bodies are all live-IDA-backed. Confidence stays below final-audit levels because original source spelling and all template declaration details are still inferred. |

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0001Q9][client_callback_dispatch](by-meta/client_callback_dispatch.md)
- [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md)
- [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md)
- [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- [UID:0003DF][0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData](by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md)
- [UID:00005N][FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___](by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md)

## 2026-06-29 Empty-Emitter Closeout

This row is the direct concrete `PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>` instantiation anchor. The reusable declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md), and child data row [UID:0003DF][0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData](by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md) covers the concrete RTTI/vtable range.

The source construction expression remains `new PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(this, &NexonclubProxyDialog::OnReplyText)`. Current MCP confirms UID0003DF has COL pointer `0x0064e8d4`, vtable base `0x00622cf4`, slots `0x0052f7c0`, `0x004f4b10`, `0x0041b6c0`, `0x0049af00`, and `0x004673f0`, with successor `0x00622d08` string `DLGMSGH.EPF`. That data should be regenerated from declarations and construction, not emitted as raw dwords.

## Changes

- 2026-06-12 Agent-A003 Batch 285: Created this concrete callback-instantiation class page so the exact `0x00622cf0-0x00622d08` callback vtable can route to its actual direct owner instead of remaining parentless or attaching to a broad proxy/file shortcut. Evidence comes from live IDA MCP decompilation, focused disassembly, `lookup_funcs`, and `xrefs_to` for the vtable store, member-function pointer, slot targets, and 24-byte object layout.
- 2026-06-26 Agent-B008 Rule 26 implementation: Added the source-facing construction expression and cross-links to the now-populated constructor/callback C++ blocks. Metadata stays `86/91`; exact original FunctionObject template/header spelling remains the score cap.
