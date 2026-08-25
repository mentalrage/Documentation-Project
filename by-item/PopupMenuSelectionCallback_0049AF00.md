*** UID:0000V8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted marker for this shared invoke range is covered by [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PopupMenuSelectionCallback 0x0049AF00

## Status

- Address range: `0x0049af00-0x0049af11`.
- Entity kind: feature-facing alias/support page for the shared FunctionObjects one-argument invoke wrapper.
- Exact memory documentation: [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md).
- Reusable callback source and emitted marker route: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
- Popup feature source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md).
- Popup concrete callback class/user: [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md).
- Suggested short alias: `PopupMenuSelectionCallback`.
- Rebuild handling: source-declared/generated-binary. This alias should not emit a second handwritten wrapper; the shared generated-template marker is on [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md), and this formal block only records the coverage relationship.

## Behavior

The exact helper reads a callback function pointer from object offset `+0x08`, computes the adjusted target from fields `+0x0c` and `+0x10`, and tail-jumps through the callback pointer. The popup `PopupMenuControlPane` binding is one concrete use of that body: the popup constructor stores vtable `0x006187e8`, target `0x00498220`, zero adjustment, and the captured pane pointer in a 24-byte callback object. Current MCP proves the same code body is also used by six non-popup callback-template vtables, so this item is an alias/support page rather than a popup-exclusive owner.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The alias records the exact range, shared FunctionObjects route, popup construction/consumer role, seven-vtable proof, sibling boundary caveat, stale `0x004d0050` rejection, and covered-by marker relationship to [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md). |
| Confidence `90` | Confidence is strong for alias behavior and source-declared/generated-binary classification because current MCP matches the exact by-memory target and seven shared vtable refs. It remains capped because this page is intentionally feature-facing support and does not reconstruct original template spelling. |

## Evidence

- Current MCP session `279422f0` reports `lookup_funcs 0x0049af00 -> sub_49AF00` size `0x11` / 17, with bytes `55 8b ec 8b c1 8b 48 10 03 48 0c 8b 40 08 5d ff e0`.
- Decompile/disasm show the adjusted member-function tail jump through offset `+0x08` using `*(this + 0x0c) + *(this + 0x10)` as the adjusted target object.
- `xrefs_to 0x0049af00` reports exactly seven data refs at `0x006187f4`, `0x0061ff7c`, `0x00620058`, `0x006200a0`, `0x00620190`, `0x00622d00`, and `0x0062ddf4`; `find_bytes "00 AF 49 00"` finds the same seven pointer slots.
- The seven vtable bases are concrete `PlainMemberFunctionObject` / `PlainMemberFunctionObjectT` callback-template tables for PopupMenuControlPane, NewUser/CreateUser dialogs, Nexonclub registration/proxy dialogs, and TerminalPane, with construction stores at `0x004980bc`, `0x0052b6a1`, `0x0052d151`, `0x0052e9c1`, `0x00530189`, `0x0055388f`, and `0x0058b567`.
- `callees 0x0049af00` reports none, and there are no ordinary direct code callers; the invoke route is through callback vtables.
- `lookup_funcs 0x0049af11` reports a separate sibling thunk, size `0x0b` / 11, beginning `81 e9 a0 00 00 00 ...`; this alias must remain the half-open `0x0049af00-0x0049af11` body.
- Current MCP session `279422f0` reports the live IDA name as `sub_49AF00`; older docs that called it a saved `PopupMenuSelectionCallbackInvoke` label are historical alias evidence, not current-session proof.
- Stale `0x004d0050` remains rejected: `lookup_funcs 0x004d0050` maps to containing `sub_4CFFB0` size `0xbf`, and `xrefs_to 0x004d0050` reports only the internal code xref at `0x004d004e`.

## Source-Structure Decision

Route the exact shared invoke body through [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) and its template policy. Keep [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) as the popup construction/consumer owner and keep [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md) as the concrete popup callback class user. Do not migrate the invoke thunk into [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md), [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md), or a caller-specific dialog source.

## Cross-References

- [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md)
- [UID:0000AN][PopupMenuControlPane](by-class/PopupMenuControlPane.md)
- [UID:00007W][MenuPane](by-class/MenuPane.md)
- [UID:00011F][0x00498040-0x00498599.PopupMenuControlPaneCore](by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md)

## Changes

- 2026-06-29 B010 UID00011X implementation callback:
  - Changed `CANONICAL_OWNER:0000AK` and `EMITTER_UIDS:0000AK` to `0000JO` so this duplicate-range alias follows the accepted FunctionObjects route.
  - Added the goal-approved covered-by marker because the page had its own blank formal C++ with a live emitter route; the emitted generated-template proof remains on [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md).
  - Updated wording from popup-exclusive wrapper ownership to feature-facing alias/support. Preserved the popup construction/consumer evidence while incorporating current MCP session `279422f0` seven-vtable proof, sibling `0x0049af11` exclusion, current `sub_49AF00` name caveat, and stale `0x004d0050` rejection.
- 2026-06-16 C001 item/IDA refresh:
  - Before: score was `85/89`; the page still referred primarily to the pre-label `sub_49AF00` state.
  - After: score was `86/90`; owner/emitter remained the older FunctionObjects wrapper class [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md), with PopupMenuControls retained as feature-side consumer.
  - Evidence: live IDA MCP reported current saved label `PopupMenuSelectionCallbackInvoke`, unchanged `0x11` half-open boundary, seven data-only callback-table refs, no callees, unchanged adjusted dispatch body, and continued rejection of `0x004d0050`.
