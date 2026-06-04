*** UID:0000V8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000AK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PopupMenuSelectionCallback 0x0049AF00

## Status

- Address range: `0x0049af00-0x0049af11`
- Entity kind: template/member-function callback invoke helper.
- Memory documentation: [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md)
- Feature source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Reusable callback type source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Exact callback-wrapper class: [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md)
- Suggested short alias: `PopupMenuSelectionCallback`
- Confidence: strong for behavior and source neighborhood; medium for final C++ template spelling.
- Rebuild handling: `source-declared/generated-binary`; the helper is compiler-emitted callback-template glue, but the source template and owning callback declarations must be reconstructed so the rebuilt binary can regenerate the equivalent invoke thunk.

## Behavior

The helper reads a callback function pointer from the callback object, adds the stored base object pointer and this-adjustment fields, and invokes the target. In generated source this is the `Invoke` method for a long `PlainMemberFunctionObject<...PopupMenuControlPane...>` template class used by [UID:0000AN][PopupMenuControlPane](by-class/PopupMenuControlPane.md) / [UID:00007W][MenuPane](by-class/MenuPane.md) selection dispatch.

## Evidence

- IDA `lookup_funcs` confirms `0x0049af00` as a real `0x11` byte function.
- IDA decompilation shows the body calls through the function pointer at object offset `+8`, passing `*(this + 12) + *(this + 16)` as the adjusted target pointer.
- IDA `xrefs_to 0x0049af00` reports data references from several vtable-like slots, so this is compiler-generated callback support rather than a normal directly-called free function.
- Use this page's short alias when linking documentation; the exact class page has a long template-instantiation name.
- The matching callback-wrapper class page is [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md).
- A stale auxiliary record also mentions `0x004d0050` as a no-op, but live IDA currently resolves that address inside `sub_4CFFB0`. Keep `0x004d0050` out of this item until IDA shows it as a standalone wrapper function.
- 2026-05-25 current-state recheck: IDA `xrefs_to 0x004d0050` reports only an internal code xref from `0x004d004e` in `sub_4CFFB0`, while `0x0049af00` has only data/vtable references.
- 2026-05-31 IDA MCP recheck: `0x0049af00` is function `sub_49AF00` with exclusive end `0x0049af11` and seven data references from vtable-like slots (`0x006187f4`, `0x0061ff7c`, `0x00620058`, `0x006200a0`, `0x00620190`, `0x00622d00`, `0x0062ddf4`). Decompilation is a single adjusted member-function call through the callback object's function pointer at offset `+8`.
- 2026-06-03 live IDA MCP recheck reconfirms `sub_49AF00` as `0x0049af00-0x0049af11`, reports no direct code callers, verifies all seven vtable-like slots hold `0x0049af00`, and shows `0x004d0050` inside `sub_4CFFB0` (`0x004cffb0-0x004d006f`) with only the internal code xref from `0x004d004e`.

## Source-Structure Decision

Attach this exact invoke helper to [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md), which in turn attaches to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md). Keep [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) as the feature-side construction and consumer owner. Do not migrate the invoke thunk into [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md), [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md), or a caller-specific dialog source.

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md)
- [UID:0000AN][PopupMenuControlPane](by-class/PopupMenuControlPane.md)
- [UID:00007W][MenuPane](by-class/MenuPane.md)
- [UID:00011F][0x00498040-0x0049b8e5.PopupMenuControlPane](by-memory/0x00498040-0x0049b8e5.PopupMenuControlPane.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable as source-declared/generated-binary callback glue, with parent attachment and C++ intentionally blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the exact function boundary, data-only vtable references, and adjusted member-function dispatch. The score remains below 95 because final template/source spelling and ownership between `FunctionObjects` and `PopupMenuControls` are not fully audited.
- 2026-06-03: Completion/confidence changed from `70/85` to `82/88`, and `AUTOGEN_PARENT_UID` set to [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md).
  - Before: the item alias had exact behavior notes but was not attached for generation and still relied on stale auxiliary provenance for the rejected `0x004d0050` caveat.
  - After: live IDA MCP independently reconfirmed the exact wrapper range, absence of direct code callers, seven data-only callback-table slots, adjusted member-function dispatch through offsets `+8`, `+12`, and `+16`, and rejection of `0x004d0050` as an interior address of `sub_4CFFB0`.
  - Remaining gap: final reconstruction C++ stays blank because the original template declaration spelling and source/header split remain below the `95/95` gate.
