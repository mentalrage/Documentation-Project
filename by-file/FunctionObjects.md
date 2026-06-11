*** UID:0000JO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FunctionObjects

## Status

- Confidence: high for shared callback utility ownership; still capped for exact original file naming.
- Proposed header-heavy module: `util/FunctionObjects.h`
- Optional companion source: `util/FunctionObjects.cpp`
- Evidence basis: current IDA MCP boundary, decompile, disassembly, vtable, byte, caller, and xref checks combined with current project-documentation cross-references.
- Meta topic: [UID:0001Q9][client_callback_dispatch](by-meta/client_callback_dispatch.md)

## File Role

`FunctionObjects` is the shared callback-object utility family used to bind object pointers, member-function pointers, and small captured arguments for UI/application callbacks. The original project likely declared most of this as templates in a header. The linker then emitted small instantiations next to the feature translation units that used them.

Do not treat each long compiler-template instantiation name as an original feature source. These are emitted template/vtable support around shared callback declarations and feature-specific construction sites.

## Proposed Contents

| Entity | Current evidence | Role |
| --- | --- | --- |
| [UID:00005K][FunctionObject](by-class/FunctionObject.md) | [UID:000123][0x0049b090-0x0049b28e.FunctionObjectDestructors](by-memory/0x0049b090-0x0049b28e.FunctionObjectDestructors.md) | `LObject`-derived callback base destructor support. |
| [UID:00005L][FunctionObject0](by-class/FunctionObject0.md) | [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md), [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md), `0x005ca28c` | Zero-argument callback base destructor and pure-virtual slot support. |
| [UID:00005M][FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____](by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md) | `0x0052a460` | String-argument callback base destructor support. |
| [UID:00005N][FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___](by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md) | `0x0052f780`, `0x0052f7c0` | Const-reference string callback base destructor support. |
| [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md) | [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) | Binds popup-menu selection dispatch to `PopupMenuControlPane`. |
| [UID:0000AJ][PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_](by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md) | [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md), [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) | Binds zero-argument application callbacks such as deferred exit/timer work. |
| [UID:0000AL][PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6](by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md) | [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md), [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md) | Binds folder-select string results back to `MusicControlDialog`. |
| [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md) | [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md), constructed by [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md) and [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md) | Dispatches a context plus two captured small arguments to [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md). |
| [UID:000040][DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528](by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md) | [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md), [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md), [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md) | Binds drop/give confirmation callbacks to `UserPane`; compiler emits the exact callback vtable in the UserPane prompt `.rdata` island. |

## Evidence Notes

- The project-structure page explicitly reserves `util/FunctionObjects.cpp` / `util/FunctionObjects.h` for this family, with header-heavy template declarations and optional emitted destructor/base support.
- [UID:0001Q9][client_callback_dispatch](by-meta/client_callback_dispatch.md) independently routes reusable callback declarations, base destructors, and virtual dispatch helpers into `FunctionObjects` while leaving construction sites in feature modules.
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) records the shared template family and known instantiations across application, popup-menu, music dialog, mix-item, and user-pane consumers.
- IDA `lookup_funcs` confirms representative callback bodies as small real functions: `0x0049af00` size `0x11`, [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) size `0x0d`, `0x004b0880` size `0x21`, `0x0052a3e0` size `0x5e`, `0x005b7450` size `0x8d`, and `0x005b77b0` size `0x18`.
- IDA `xrefs_to` for these bodies are data/vtable references rather than normal code callers, which is expected for virtual callback objects.
- 2026-05-26 IDA MCP recheck reconfirms those representative boundaries and reports no direct code callers for the invoke wrappers.
- Current IDA decompilation shows consistent callback layouts: callback function pointer, bound object pointer, optional `this` adjustment, and optional captured small parameters.
- [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) returns a 24-byte object size and has many vtable data references, supporting a shared callback-object virtual slot rather than a feature method.
- 2026-06-10 B001-014 split of [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) confirms that only the exact callback children in that span belong here. The broad container also contains StringBase, Application, PasswordError, RegistryConfig, WinMain, and Application cleanup helpers, so it must remain a parent-blank mixed inventory rather than a `FunctionObjects` child.
- IDA MCP decompilation on 2026-05-25 resolves the `0x004b0880` construction-site question: `sub_4AFCC0` and `sub_4B0120` construct the `DoubleParamMemberFunctionObject<MixItemDialog,...>` object and pass it into `NumberInputDialog`; `ExchangeAlertPane::OnButtonClick` at `0x004b0820` is separate alert button logic.
- 2026-05-31 IDA MCP recheck confirms representative callback wrappers as vtable/data-referenced helper code with no direct callers; `0x0052a3e0-0x0052a43e` and `0x0052a4a0-0x0052a4de` now have exact by-memory pages for the MusicControlDialog folder-selection callback wrapper.
- 2026-06-05 IDA MCP confirms [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) as the 24-byte `UserPane` double-parameter callback construction helper and [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) as its vtable invoke slot.
- 2026-06-07 Batch 050 split-recheck adds [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md), proving the exact compiler-emitted vtable extent that pairs with the construction helper and invoke slot.
- 2026-06-08 Batch 116 split-recheck ties the MixItemDialog double-param callback to exact construction sites [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md) and [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md), with callback target [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md).

## Ownership Notes

Feature modules should own the code that allocates and configures these callback objects. `FunctionObjects` should own the reusable callback type declarations and base behavior.

Current feature consumers include [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md), [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md), [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md), [UID:0000HG][Application](by-file/Application.md), and [UID:0000P1][UserPane](by-file/UserPane.md).

`StringUtil.cpp` should not absorb the `FunctionObjectT<mystr::StringBase<...>>` files only because the template parameter is a string type. Those instantiations are callback-template support.

## Attachment Policy

Pages for compiler-emitted `FunctionObject*` instantiations may use this file as `AUTOGEN_PARENT_UID` when their own type/function evidence is at least high-confidence and the page describes reusable callback support rather than feature-specific construction. Keep feature-specific invoke wrappers cross-linked to their consumer modules, but do not move constructor/allocation ownership out of those modules only because the callback object type lives here.

The confidence score is raised only to the minimum parent-link threshold because the shared utility role is well supported but the exact original source split is still inferred. Final source could have been a mostly header-only `FunctionObjects.h`, a small companion `.cpp`, or a project-specific callback header with a different basename.

## Compiler-Artifact Caveats

- Long compiler-template names are artifacts and can be hashed or truncated. Prefer the short docs in this family when cross-referencing.
- Some base destructor bodies appear more than once with identical behavior. Treat those as emitted vtable/template support until final source emission decides whether to keep one helper body or multiple linked instantiations.
- `0x004b0880` is physically interleaved in the exchange/mix tail, but construction-site evidence ties it to `MixItemDialog` quantity callbacks passed into `NumberInputDialog`. Keep the exchange-tail link as a boundary caveat, not as alert ownership.
- The feature-owned construction sites and callback target remain with [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) / [UID:00008J][MixItemDialog](by-class/MixItemDialog.md). `FunctionObjects` owns the reusable callback-template declaration and emitted invoke wrapper context, not the item-mixing workflow.
- `0x004d0050` appears in older notes for the popup-menu callback wrapper, but IDA MCP resolves it inside a different function (`sub_4CFFB0`) rather than as a standalone no-op. A current `xrefs_to` check reports only the internal code xref at `0x004d004e`. Keep it out of confirmed `FunctionObjects` method lists until direct binary evidence supports a separate function.

## Cross-References

- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0001Q9][client_callback_dispatch](by-meta/client_callback_dispatch.md)
- [UID:000123][0x0049b090-0x0049b28e.FunctionObjectDestructors](by-memory/0x0049b090-0x0049b28e.FunctionObjectDestructors.md)
- [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md)
- [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md)
- [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md)
- [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md)
- [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md)
- [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md)
- [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md)
- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md)
- [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md)
- [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)
- [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md)

## Changes

- 2026-06-10 B001-014 mixed-container split:
  - Score unchanged at `87/85`.
  - Replaced raw `0x004671a0`, `0x004671f0`, `0x004672c0`, and `0x004673f0` references with exact child pages [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md), [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md), [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md), and [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md).
  - Evidence: IDA MCP confirms these exact rows are callback-template support, while [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) is mixed and should remain parent-blank.

- 2026-06-02 parent-link confidence refinement:
  - What existed before: `COMPLETION:82` and `CONFIDENCE:76`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: existing project-structure, meta-dispatch, template-family, and IDA vtable/data-xref evidence now supports using this file as a parent for high-confidence compiler-emitted `FunctionObject*` template pages. Confidence remains capped at 80 because exact original header/source naming is still not proven.
- 2026-06-05 UserPane callback refresh:
  - Before: the page still cited stale provenance and only listed the `UserPane` callback invoke body by raw address.
  - After: raised to `86/84`, removed stale provenance wording, linked the exact [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) construction helper, and updated evidence to current IDA MCP boundary/decompile/vtable/caller checks.
  - Evidence: current IDA MCP confirms the callback construction helper, vtable `0x00630a78`, invoke slot `0x00630a84`, object field layout, four drop/give callers, and the existing `0x005b77b0-0x005b77c8` invoke body.
- 2026-06-07 Batch 050 callback-vtable split:
  - Before: `86/84`, with the `UserPane` callback construction/invoke evidence but no exact `.rdata` vtable child.
  - After: `87/85`, adding the exact [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md) child and confirming the parent gate for the concrete [UID:000040][DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528](by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md) instantiation.
  - Evidence: live IDA MCP confirms vtable base `0x00630a78`, construction-store xref `0x005b7495`, invoke slot `0x00630a84 -> 0x005b77b0`, and boundary before the following drop-confirmation string.
- 2026-06-08 Batch 116 MixItemDialog callback construction refresh:
  - Before: the page listed the MixItemDialog double-param callback invoke wrapper but did not link the exact quantity helper/callback children.
  - After: added [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md) and [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md) as construction/target evidence for the `0x004b0880` callback wrapper. Score remains `87/85` because this refines one known feature consumer rather than resolving the remaining exact original header/source split.
  - Evidence: current IDA MCP confirms `0x004afcc0` and `0x004b0120` construct the callback object and target `0x004afe40` for stackable item quantity selection.
- 2026-06-01 reconstruction path fill-in:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank while the body proposed `util/FunctionObjects.h` with an optional `util/FunctionObjects.cpp`.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: path now matches the documented shared utility/template role and gives callback-template memory rows a stable file-level reconstruction parent without forcing long compiler-template instantiation names into source.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: reusable callback-template roles, representative IDA boundaries, xref behavior, feature consumers, construction-site evidence, and compiler-artifact caveats are documented; confidence remains medium-high because original source naming, header-heavy template emission, and duplicate emitted artifacts are still unresolved.
