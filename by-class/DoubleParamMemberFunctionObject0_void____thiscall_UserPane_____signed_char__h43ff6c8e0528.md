*** UID:000040 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528

## Status

- Confidence: strong for `UserPane` drop/give confirmation callback role.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support, instantiated by drop/give input pane code.
- Rebuild handling: `source-declared/generated-binary`; the rebuilt source should declare the reusable callback template and let the compiler emit the concrete instantiation.
- Constructor helper: [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- Related memory: [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)
- Vtable data: [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md)
- Reconstructable class/template instantiation attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md). Final C++ stays blank because exact original template/header spelling remains below the 95/95 final-source gate.

## Class Purpose

This callback wrapper binds a `UserPane` member function with two captured arguments: a signed slot-like byte and a boolean. Current IDA MCP evidence ties construction to drop/give confirmation prompt paths.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| construction helper | `0x005b7450-0x005b74dd` | Allocates a 24-byte callback object, initializes the function-object base, installs vtable `0x00630a78`, and stores callback pointer/object/slot/flag fields. |
| `Invoke` | `0x005b77b0-0x005b77c8` | Applies the stored object adjustment and calls the captured `UserPane` callback with the stored signed-char and bool values. |
| vtable data | `0x00630a78-0x00630a90` | Compiler-emitted `DoubleParamMemberFunctionObject0<UserPane,...>` vtable split from the UserPane prompt string island. |

## Evidence Notes

- IDA `lookup_funcs` confirms `sub_5B7450` as a real `0x8d` byte construction helper and `sub_5B77B0` as a real `0x18` byte invoke wrapper.
- IDA `decompile 0x005b7450` shows allocation of 24 bytes, base initializer `sub_4F4A80`, vtable store `0x00630a78`, callback pointer at `+0x08`, object adjustment at `+0x0c`, target object pointer at `+0x10`, slot byte at `+0x14`, and bool flag at `+0x15`.
- IDA `decompile 0x005b77b0` shows the invoke wrapper calling `*(this + 0x08)` with adjusted target `*(this + 0x0c) + *(this + 0x10)` and the captured bytes at `+0x14` / `+0x15`.
- IDA `callers` / `xrefs_to 0x005b7450` report four construction callers from [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md), [UID:000044][DropInputPane](by-class/DropInputPane.md), [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md), and [UID:00005U][GiveInputPane](by-class/GiveInputPane.md).
- IDA `xrefs_to 0x005b77b0` reports the vtable/data reference at `0x00630a84`; direct callers are absent, matching virtual callback dispatch.
- Byte checks confirm `0x005b7447-0x005b7450` and `0x005b74dd-0x005b74e0` are `0xcc` padding around the construction helper, and `0x005b77c8` starts the next function after the invoke wrapper.
- 2026-06-07 Batch 050 live IDA MCP rechecked the vtable data child: `0x00630a78` is named as the concrete `DoubleParamMemberFunctionObject0<UserPane,...>` vtable, `0x005b7495` stores that vtable in the construction helper, `0x00630a84` points to the invoke wrapper at `0x005b77b0`, and `0x00630a90` starts the following drop-confirmation string.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md)
- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md)
- [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the callback invoke wrapper at `0x005b77b0` as a real `0x18` byte function. At that point, `AUTOGEN_PARENT_UID` stayed blank because the callback-instantiation page was below the 80 completion parent-attachment gate even though [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) was the likely source-family parent.
- 2026-06-05: Raised from `76/84` to `84/88` and attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
  - Before: the page still cited stale provenance, lacked the exact construction helper page, and stayed below the parent-attachment gate.
  - After: removed stale provenance, documented current IDA evidence for both constructor helper and invoke wrapper, linked the new [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) split, and attached the class/template instantiation to the FunctionObjects source family.
  - Evidence: current IDA MCP confirms `0x005b7450-0x005b74dd`, `0x005b77b0-0x005b77c8`, vtable `0x00630a78`, invoke slot `0x00630a84`, object fields, four drop/give callers, and adjacent padding.
- 2026-06-07 Batch 050 vtable-child split:
  - Before: `84/88`, with constructor and invoke evidence but the `.rdata` vtable still embedded only in the broad UserPane strings page.
  - After: `85/89`, adding [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md) as the exact compiler-emitted vtable child.
  - Evidence: live IDA MCP confirms vtable base `0x00630a78`, construction-store xref `0x005b7495`, invoke slot `0x00630a84 -> 0x005b77b0`, and `0x00630a90` as the following string boundary.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: callback wrapper role, invoke method, vtable xref, object layout, and drop/give `UserPane` construction-site ownership are documented; remaining uncertainty is final source-facing template/header spelling.
