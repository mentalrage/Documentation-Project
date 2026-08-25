*** UID:000041 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete MixItemDialog double-parameter callback instantiation.
// The reusable FunctionObjects template declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md);
// the generated invoke wrapper is covered by [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d

## Status

- Confidence: strong for generated double-parameter callback role and MixItemDialog construction-site evidence, medium for final template/header naming.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support.
- Source-facing placement: shared callback-template declaration emitted from [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), with feature construction sites kept in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) and [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md) callers. [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) is the generated source root, while this concrete class is the direct owner/emitter for exact invoke wrapper [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md).
- Related memory: [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md), owned/emitted by this concrete callback class.
- Vtable/layout anchor: [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md); mixed index [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- Reconstructable: true as compiler-emitted project callback-template glue. The exact invoke wrapper [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) now carries a formal comment-only generated-template marker; do not reconstruct it as a handwritten wrapper body.

## Class Purpose

This generated wrapper dispatches a callback with one runtime context argument and two captured small arguments. The expanded metadata name resolves to a `MixItemDialog` member-function wrapper with `unsigned long`, `signed char`, and `unsigned char` argument types.

Do not reconstruct this as a standalone feature source file. [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) owns the reusable template declaration, while the `MixItemDialog` quantity paths own allocation/configuration of the specific callback object passed into [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md).

For ownership purposes, this concrete class owns/emits the exact compiler-generated invoke wrapper [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md). [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) remains the FunctionObjects source root and generated output route, not the direct owner of the wrapper body. The feature-side `MixItemDialog` docs remain construction and callback-target context rather than wrapper ownership.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Invoke(unsigned long context)` | [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) | Compiler-emitted invoke slot owned/emitted by this concrete class; calls the stored member callback with the runtime context plus two bound parameters and emits only a formal comment marker at target level. |

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
- B012 current MCP session `c9671f69` refines the exact invoke wrapper [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) to `0x004b0880-0x004b08a1`, size `0x21` / 33 bytes, with exact bytes `55 8b ec 8b d1 0f b6 42 15 8b 4a 10 03 4a 0c 50 0f b6 42 14 50 ff 75 08 8b 42 08 ff d0 5d c2 04 00` and unique signature `55 8B EC 8B D1 0F B6 42 ? 8B 4A ? 03 4A ? 50 0F B6 42 ? 50 FF 75 ? 8B 42 ? FF D0 5D C2 04 00`.
- B012 confirms [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md) slot `0x0061a3bc -> 0x004b0880`; current MCP names the vtable base `0x0061a3b0` as `??_7?$DoubleParamMemberFunctionObject@P8MixItemDialog@@AEXKCE@ZV1@CE@@6B@`.
- B012 confirms the two construction paths: `sub_4AFCC0` stores this class vtable at `0x004afd62` and bound target `0x004afe40` at `0x004afd68`; `sub_4B0120` stores the same vtable at `0x004b0370` and the same target at `0x004b0376`.
- B012 confirms the wrapper's decompile/disassembly forwarding behavior: stored member pointer at `+0x08`, adjusted object pointer from `+0x0c/+0x10`, runtime argument forwarded from the stack, captured bytes at `+0x14/+0x15`, indirect call, and `retn 4`.
- 2026-06-12 A004 split refresh added source-local by-vtable child [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md), routed here after the child/direct parent gate cleared. B001-00025A later corrected the child to `88/92` over exact range `0x0061a3ac-0x0061a3c4`, including tail slot `0x0061a3c0 -> 0x004673f0` before the `FieldMapPane` COL successor at `0x0061a3c4`.
- IDA MCP decompilation shows `sub_4AFCC0` and `sub_4B0120` constructing this object in `MixItemDialog`/`AddMixingItemDialog` quantity paths and passing it to `NumberInputDialog`.
- The construction sites allocate a 24-byte callback object, install the `DoubleParamMemberFunctionObject<MixItemDialog,...>` vtable, store bound target `sub_4AFE40`, bind the `MixItemDialog` object, and pass the object to the number prompt.
- `callers 0x004b0880` and `callees 0x004b0880` are empty, which matches virtual-dispatched template glue; the direct call target is the stored member pointer, not a normal static callee.
- Existing exchange-tail docs mention this address because it sits in an interleaved exchange/item/mix tail island. Construction-site evidence now favors MixItemDialog/NumberInput ownership rather than ExchangeAlertPane ownership.

## Score Rationale

- Completion remains `85` because the class has the parent/source-root attachment, exact invoke child, ABI/layout offsets, vtable/data reference, construction stores, bound target, NumberInput handoff, and exchange-tail ownership caveat documented strongly enough for assignment under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
- Confidence remains `88` because current by-memory, vtable, and template-family pages agree on the exact wrapper behavior and source family. B012 raises the exact child [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) to `87/90`, but this class page stays below final-source quality because the original template spelling and header-heavy source split are still inferred.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)

## 2026-06-29 Empty-Emitter Closeout

This row is a concrete MixItemDialog quantity-callback instantiation anchor, not a second home for the shared FunctionObjects template declaration. The reusable declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md). The exact generated invoke-wrapper row is [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md), which already carries the accepted comment-only generated-template marker.

The callback object's source ownership remains the shared FunctionObjects family while feature-specific construction and target behavior remain with the MixItemDialog/ItemDialogs flow. Do not emit a handwritten invoke body or duplicate the reusable template declaration here.

## Changes

- 2026-06-29 B012 UID00014W empty-emitter implementation:
  - Score unchanged at `85/88`.
  - Recorded [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) as the exact invoke wrapper owned/emitted by this concrete callback class, while [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) remains the generated source root.
  - Added current MCP session `c9671f69` evidence for exact size/bytes/signature, vtable slot [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md) `0x0061a3bc -> 0x004b0880`, construction stores `0x004afd62/0x004afd68` and `0x004b0370/0x004b0376`, bound target `0x004afe40`, and forwarding fields `+0x08/+0x0c/+0x10/+0x14/+0x15`.
  - Preserved the policy that this is compiler-emitted FunctionObjects glue: the target emits a formal comment-only marker, not a handwritten wrapper body.
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
- 2026-06-12 A004 vtable split:
  - Added source-local callback vtable child [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md); score remains `85/88`.
  - Evidence: live IDA MCP reconfirmed the exact callback-template vtable record and construction/invoke evidence.
