*** UID:0001Q9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Callback Dispatch

## Scope

This page tracks reusable callback-object infrastructure used by UI, application, dialog, and panel code. It is a source-structure topic, not a packet or event-routing spec. Exact code ranges live in `by-memory`; concrete wrapper classes live in `by-class`; likely original ownership lives in [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).

## Current Model

The client uses small heap or stack callback objects with vtable-dispatched `Invoke` methods. Generated names such as `PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_` are compiler/template artifacts that preserve the target class and argument shape, but they are not strong evidence for standalone source files.

Observed callback-object fields usually include:

| Field family | Meaning |
| --- | --- |
| base/vtable slot | `LObject` or callback-base virtual identity. |
| callback function pointer | The target member-function dispatch pointer. |
| bound object pointer | Captured target object or adjusted base value. |
| this adjustment | Offset/value added before dispatch. |
| captured arguments | Small stored values such as slot ids, booleans, item indexes, or string payloads. |

## Source-Structure Guidance

- Keep reusable declarations and base destructor support with [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), likely as a header-heavy `util/FunctionObjects.h` plus optional emitted support in `util/FunctionObjects.cpp`.
- Keep construction sites with the feature module that knows the target object and callback semantics.
- Do not migrate every generated `class_*FunctionObject*.cpp` file as an original source file.
- Treat vtable-only `xrefs_to` as expected evidence for virtual callback objects; lack of direct callers is normal for these tiny invoke helpers.
- Recheck generated metadata carefully. Current data includes at least one stale callback-wrapper assignment: `0x004d0050` is listed as a popup-menu no-op in metadata/disabled output, but IDA places it inside `ImageLib::ImageLib`.
- 2026-05-26 recheck: the representative invoke wrappers still have vtable/data xrefs and no modeled direct callers; active `simroot_v2` still emits nine standalone FunctionObject template-instantiation files.

## Confirmed Examples

| Callback family | Confirmed memory | Feature consumer | Notes |
| --- | --- | --- | --- |
| `FunctionObject` callback/base destructors | [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md), [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md) | shared utility | B001-000123 separates `0x0049b090` as shared 24-byte callback-template scalar deleting destructor support routed through FunctionObjects; B001-0003LP confirms `0x0049b250` as the base `FunctionObject::vftable` scalar deleting destructor routed through the `FunctionObject` class. |
| Popup-menu selection callback | [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) | [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) | Dispatches selected popup value to `PopupMenuControlPane`. |
| Application zero-argument callbacks | [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md), [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) | [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), with [UID:0000HG][Application](by-file/Application.md) as the feature consumer | Deferred application callback wrappers; [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) is now only a mixed split inventory. |
| MixItemDialog quantity callback | [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) | [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) / [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md) | Constructed in mix-item paths and passed to `NumberInputDialog`. |
| UserPane double-parameter callback | [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) | [UID:0000P1][UserPane](by-file/UserPane.md) | Drop/give confirmation callback wrapper. |

## Data Caveats

- `0x004d0050` is currently a Wave3 data issue for the popup-menu callback wrapper. Use [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) as the confirmed range.
- Some callback base destructor bodies appear multiple times with identical behavior. Treat them as compiler-emitted support until final source emission decides whether to keep one helper body or multiple linked instantiations.
- B001-000123 refined this caveat: do not treat every body that writes `FunctionObject::vftable` as the base vtable's own destructor. `0x0049b090` is callback-template support because its refs are concrete callback vtables and its guard path uses the 24-byte callback-object size. B001-0003LP confirms `0x0049b250` as the base vtable destructor through the sole data xref from `0x006186a8`, the FunctionObject RTTI locator at `0x006186a4`, and `__purecall` slots at `0x006186b4/0x006186b8`.
- `0x004b0880` should remain MixItemDialog/NumberInput callback-template support. Current IDA construction-site evidence does not support ExchangeAlertPane ownership.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00005K][FunctionObject](by-class/FunctionObject.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)
- [Wave3 data issues](../wave3_data_issues.md)
