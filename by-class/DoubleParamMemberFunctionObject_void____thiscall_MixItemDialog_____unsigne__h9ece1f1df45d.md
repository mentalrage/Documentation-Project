*** UID:000041 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d

## Status

- Confidence: strong for generated double-parameter callback role and MixItemDialog construction-site evidence, medium for final template/header naming.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support.
- Source-facing placement: shared callback-template declaration emitted from [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), with feature construction sites kept in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) and [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md) callers.
- Related memory: [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- Reconstructable: true as compiler-emitted project callback-template glue; final C++ remains blank because the original template declaration and header/source split are below the final-source gate.

## Class Purpose

This generated wrapper dispatches a callback with one runtime context argument and two captured small arguments. The expanded metadata name resolves to a `MixItemDialog` member-function wrapper with `unsigned long`, `signed char`, and `unsigned char` argument types.

Do not reconstruct this as a standalone feature source file. [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) owns the reusable template declaration, while the `MixItemDialog` quantity paths own allocation/configuration of the specific callback object passed into [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Invoke(unsigned long context)` | `0x004b0880-0x004b08a1` | Calls the stored member callback with the runtime context plus two bound parameters. |

## Wrapper ABI

The exact child page documents the emitted wrapper at `82/88`. Its current object shape is:

| Offset | Role |
| --- | --- |
| `+0x08` | Stored member/callback function pointer reached by indirect `call eax`. |
| `+0x0c` | Bound object/context pointer. |
| `+0x10` | `this` adjustor dword added to the bound object before dispatch. |
| `+0x14` | First captured byte argument. |
| `+0x15` | Second captured byte argument. |
| stack arg `[ebp+8]` | Runtime argument forwarded unchanged as the callback's context/value parameter. |

The resulting call shape is `callback(adjustedMixDialog, runtimeArg, captured0, captured1)`, matching the documented `DoubleParamMemberFunctionObject<..., unsigned char, unsigned char>` family.

## Evidence Notes

- IDA `lookup_funcs 0x004b0880` confirms a real `0x21` byte function.
- IDA `xrefs_to 0x004b0880` reports a vtable/data reference at `0x0061a3bc`.
- IDA `list_globals` confirms the owning callback vtable at `0x0061a3b0`; `xrefs_to 0x0061a3b0` reports construction stores at `0x004afd62` and `0x004b0370`.
- IDA MCP decompilation shows `sub_4AFCC0` and `sub_4B0120` constructing this object in `MixItemDialog`/`AddMixingItemDialog` quantity paths and passing it to `NumberInputDialog`.
- The construction sites allocate a 24-byte callback object, install the `DoubleParamMemberFunctionObject<MixItemDialog,...>` vtable, store bound target `sub_4AFE40`, bind the `MixItemDialog` object, and pass the object to the number prompt.
- `callers 0x004b0880` and `callees 0x004b0880` are empty, which matches virtual-dispatched template glue; the direct call target is the stored member pointer, not a normal static callee.
- Existing exchange-tail docs mention this address because it sits in an interleaved exchange/item/mix tail island. Construction-site evidence now favors MixItemDialog/NumberInput ownership rather than ExchangeAlertPane ownership.

## Score Rationale

- Completion is `85` because the class now has the parent attachment, exact invoke child, ABI/layout offsets, vtable/data reference, construction stores, bound target, NumberInput handoff, and exchange-tail ownership caveat documented strongly enough for assignment under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
- Confidence is `88` because current by-memory and template-family pages agree on the exact wrapper behavior and source family; it remains below final-source quality because the original template spelling and header-heavy source split are inferred.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the callback invoke wrapper at `0x004b0880` as a real `0x21` byte function. Left `AUTOGEN_PARENT_UID` blank because this generated callback-instantiation page is below the 80 completion parent-attachment gate even though [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) is the likely source-family parent.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/82`.
  - Summary/evidence: callback wrapper role, invoke method, vtable xref, MixItemDialog construction sites, NumberInputDialog handoff, and exchange-tail ownership caveat are documented; remaining uncertainty is final template/header naming.
- 2026-06-07 A001 template-parent refresh:
  - Before: the page remained at `76/82`, had a blank parent, and still used generated-file wording even though its exact child memory page and the shared template-family docs were stronger.
  - After: raised to `82/88`, attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), replaced generated-file wording with source-facing template placement, and added ABI/layout, construction-site, vtable, and score-rationale notes.
  - Summary/evidence: [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md), [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md), [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), and [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md) agree that this is reconstructable callback-template glue emitted for `MixItemDialog` quantity callbacks, not a separate original feature class.
- 2026-06-10 B001-026 gate repair:
  - Before: completion was `82`, below the strict reconstructable child threshold.
  - After: `85/88`; direct parent [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) is `87/85`.
  - Evidence: exact wrapper ABI, vtable ref, construction stores at `0x004afd62` and `0x004b0370`, bound target `0x004afe40`, and NumberInput handoff are sufficient for template-glue ownership. Final template spelling remains below source-emission quality.
