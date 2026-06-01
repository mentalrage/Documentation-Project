*** UID:0000JO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FunctionObjects

## Status

- Confidence: medium for original source name, strong for support/template role.
- Proposed header-heavy module: `util/FunctionObjects.h`
- Optional companion source: `util/FunctionObjects.cpp`
- Current recovered sources: the `source-3/simroot_v2/class_*FunctionObject*.cpp` family.
- Evidence basis: `simroot_v2` generated output, cached prewave function records, and IDA MCP `lookup_funcs` / `xrefs_to` checks through 2026-05-26.
- Meta topic: [UID:0001Q9][client_callback_dispatch](by-meta/client_callback_dispatch.md)

## File Role

`FunctionObjects` is the shared callback-object utility family used to bind object pointers, member-function pointers, and small captured arguments for UI/application callbacks. The original project likely declared most of this as templates in a header. The linker then emitted small instantiations next to the feature translation units that used them.

Do not treat each long generated `class_*FunctionObject*.cpp` file as an original feature source. They are staging containers for compiler-emitted template/vtable support.

## Proposed Contents

| Entity | Current evidence | Role |
| --- | --- | --- |
| [UID:00005K][FunctionObject](by-class/FunctionObject.md) | [UID:000123][0x0049b090-0x0049b28e.FunctionObjectDestructors](by-memory/0x0049b090-0x0049b28e.FunctionObjectDestructors.md) | `LObject`-derived callback base destructor support. |
| [UID:00005L][FunctionObject0](by-class/FunctionObject0.md) | `0x004671f0`, `0x004672c0`, `0x005ca28c` | Zero-argument callback base destructor and pure-virtual slot support. |
| [UID:00005M][FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____](by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md) | `0x0052a460` | String-argument callback base destructor support. |
| [UID:00005N][FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___](by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md) | `0x0052f780`, `0x0052f7c0` | Const-reference string callback base destructor support. |
| [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md) | [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) | Binds popup-menu selection dispatch to `PopupMenuControlPane`. |
| [UID:0000AJ][PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_](by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md) | `0x004671a0`, `0x004673f0` | Binds zero-argument application callbacks such as deferred exit/timer work. |
| [UID:0000AL][PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6](by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md) | [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md), [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md) | Binds folder-select string results back to `MusicControlDialog`. |
| [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md) | `0x004b0880` | Dispatches a context plus two captured small arguments. |
| [UID:000040][DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528](by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md) | `0x005b77b0` | Binds drop/give confirmation callbacks to `UserPane`. |

## Evidence Notes

- IDA `lookup_funcs` confirms representative callback bodies as small real functions: `0x0049af00` size `0x11`, `0x004671a0` size `0x0d`, `0x004b0880` size `0x21`, `0x0052a3e0` size `0x5e`, and `0x005b77b0` size `0x18`.
- IDA `xrefs_to` for these bodies are data/vtable references rather than normal code callers, which is expected for virtual callback objects.
- 2026-05-26 IDA MCP recheck reconfirms those representative boundaries and reports no direct code callers for the invoke wrappers.
- Generated source shows consistent layouts: callback function pointer, bound object pointer, optional `this` adjustment, and optional captured small parameters.
- `0x004673f0` returns a 24-byte object size and has many vtable data references, suggesting a shared callback-object virtual slot rather than a feature method.
- IDA MCP decompilation on 2026-05-25 resolves the `0x004b0880` construction-site question: `sub_4AFCC0` and `sub_4B0120` construct the `DoubleParamMemberFunctionObject<MixItemDialog,...>` object and pass it into `NumberInputDialog`; `ExchangeAlertPane::OnButtonClick` at `0x004b0820` is separate alert button logic.
- 2026-05-26 current-state recheck finds the same nine active `class_*FunctionObject*.cpp` files under `simroot_v2`.
- 2026-05-31 IDA MCP recheck confirms representative callback wrappers as vtable/data-referenced helper code with no direct callers; `0x0052a3e0-0x0052a43e` and `0x0052a4a0-0x0052a4de` now have exact by-memory pages for the MusicControlDialog folder-selection callback wrapper.

## Ownership Notes

Feature modules should own the code that allocates and configures these callback objects. `FunctionObjects` should own the reusable callback type declarations and base behavior.

Current feature consumers include [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md), [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md), [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md), [UID:0000HG][Application](by-file/Application.md), and [UID:0000P1][UserPane](by-file/UserPane.md).

`StringUtil.cpp` should not absorb the `FunctionObjectT<mystr::StringBase<...>>` files only because the template parameter is a string type. Those instantiations are callback-template support.

## Generated Output Caveats

- Long generated filenames are compiler/template artifacts and can be hashed or truncated. Prefer the short docs in this family when cross-referencing.
- Some base destructor bodies appear more than once with identical behavior. Treat those as emitted vtable/template support until final source emission decides whether to keep one helper body or multiple linked instantiations.
- `0x004b0880` is physically interleaved in the exchange/mix tail, but construction-site evidence ties it to `MixItemDialog` quantity callbacks passed into `NumberInputDialog`. Keep the exchange-tail link as a boundary caveat, not as alert ownership.
- `0x004d0050` appears in the generated metadata and disabled source for the popup-menu callback wrapper, but IDA MCP resolves it inside a different function (`sub_4CFFB0`) rather than as a standalone no-op. A current `xrefs_to` check reports only the internal code xref at `0x004d004e`. Keep it out of confirmed `FunctionObjects` method lists until Wave3 data is refreshed.

## Cross-References

- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0001Q9][client_callback_dispatch](by-meta/client_callback_dispatch.md)
- [UID:000123][0x0049b090-0x0049b28e.FunctionObjectDestructors](by-memory/0x0049b090-0x0049b28e.FunctionObjectDestructors.md)
- [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md)
- [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md)
- [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md)
- [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md)
- [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)

## Changes

- 2026-06-01 reconstruction path fill-in:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank while the body proposed `util/FunctionObjects.h` with an optional `util/FunctionObjects.cpp`.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: path now matches the documented shared utility/template role and gives callback-template memory rows a stable file-level reconstruction parent without forcing long generated class filenames into source.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: reusable callback-template roles, representative IDA boundaries, xref behavior, feature consumers, construction-site evidence, and generated-output caveats are documented; confidence remains medium-high because original source naming, header-heavy template emission, and duplicate generated artifacts are still unresolved.
