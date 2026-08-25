*** UID:0000AK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete PlainMemberFunctionObject<PopupMenuControlPane, long> instantiation.
// The reusable declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md); the invoke wrapper is covered by [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_

## Status

- Confidence: strong for the popup-menu concrete callback instantiation and construction route.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support, instantiated by [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md).
- Autogen source owner: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) under `NexusTK/util/`; [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) remains the popup-menu construction and consumer owner.
- Short item alias: [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)
- Memory documentation: [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md)
- Parent gate: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) is above `80/80`, and this class page now clears the child-side threshold for source-family attachment.

## Class Purpose

This page documents the concrete popup-menu `PlainMemberFunctionObject` instantiation that uses the shared one-argument FunctionObjects invoke body at [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md). It is a real popup construction/consumer context, but UID00011X is now owned/emitted by [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) because current MCP proves the same folded invoke body is used by six non-popup callback-template vtables. Use `PopupMenuSelectionCallback` in feature docs when a short alias is clearer.

## Source Ownership And Autogen

- Rebuild handling: source-declared/generated-binary. The reusable callback template/type declaration must be available to the rebuilt project, while the exact vtable/function bytes should be emitted by the compiler from the template/source declaration.
- Parent attachment: this class attaches to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), whose documented policy permits high-confidence generated `FunctionObject*` instantiations that describe reusable callback support.
- Feature ownership caveat: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) owns allocation, configuration, and use of this callback for popup menu selection; it does not own the reusable callback type itself.
- Shared invoke child: [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) is no longer popup-exclusive. It carries the accepted generated-template marker through [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), while this class page remains a concrete popup instantiation/support child.
- Final C++ on this class page remains blank because the exact original template declaration/source spelling is still below the class-level final-body gate; the exact emitted invoke marker belongs on UID00011X.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Invoke` | `0x0049af00-0x0049af11` | Shared/folded FunctionObjects invoke body used by this class's vtable slot; reads the stored callback and target/adjustment fields, then tail-jumps to the callback. |

## Rejected Stale Metadata

Stale auxiliary metadata lists a `NoOp` method at `0x004d0050`, but IDA MCP `lookup_funcs` on 2026-05-25 resolves that address inside `sub_4CFFB0` (`0x004cffb0-0x004d006f`) rather than as a standalone no-op callback method. Do not treat `0x004d0050` as confirmed ownership for this class unless live IDA evidence later proves a standalone function there.

2026-05-25 current-state recheck: IDA `xrefs_to 0x004d0050` reports only the internal code xref at `0x004d004e` inside `sub_4CFFB0`; this remains a metadata issue, not a confirmed wrapper method.

## Evidence Notes

- IDA `lookup_funcs 0x0049af00` confirms a real `0x11` byte function.
- IDA `xrefs_to 0x0049af00` reports data references from several vtable-like slots, consistent with a virtual callback object.
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) already owns the feature allocation/consumer side.
- [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) records live IDA confirmation of the exact invoke span, no direct code callers, seven callback-table slots, the adjusted member-function dispatch body, and the stale `0x004d0050` rejection.
- 2026-06-14 live IDA MCP reconfirms `0x0049af00-0x0049af11` as `sub_49AF00`, decompiles the body to a single indirect call through `this+8` using `*(this+12) + *(this+16)` as the adjusted target, reports seven data xrefs and no direct callers, and confirms `0x004d0050` lies inside `sub_4CFFB0` rather than a standalone wrapper method.
- 2026-06-29 B010 current MCP session `279422f0` proves the seven refs are shared vtable invoke slots at `0x006187f4`, `0x0061ff7c`, `0x00620058`, `0x006200a0`, `0x00620190`, `0x00622d00`, and `0x0062ddf4`. The popup slot `0x006187f4` is one of seven: non-popup slots cover NewUser/CreateUser dialogs, Nexonclub registration/proxy dialogs, and TerminalPane. The popup construction site still stores the popup vtable at `0x004980bc`, target `0x00498220` at `+0x08`, zero adjustment at `+0x0c`, and the captured pane pointer at `+0x10`.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `85` | The page records the popup-menu concrete callback instantiation, FunctionObjects/PopupMenuControls ownership split, shared invoke child, current live IDA evidence, parent gate, stale metadata rejection, source-declared/generated-binary rebuild handling, and class-level final C++ blocker. |
| Confidence | `86` | IDA-confirmed invoke bounds/xrefs, popup construction evidence, and FunctionObjects attachment policy strongly support the interpretation. Confidence remains capped because the long generated template spelling and class-level source declaration shape are not yet source-final. |

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)
- [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md)
- [UID:0000AN][PopupMenuControlPane](by-class/PopupMenuControlPane.md)

## 2026-06-29 Empty-Emitter Closeout

This row is the concrete `PlainMemberFunctionObject<PopupMenuControlPane, long>` instantiation anchor. The reusable declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md), and the exact invoke wrapper is covered by [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md).

Shared destructor support routed through [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) is compiler scalar deleting destructor glue. Under the accepted scalar-destructor policy it is non-emitting with a blank formal block, not a handwritten destructor body and not a comment-only marker left in generated output.

## Changes

- 2026-06-29 B010 UID00011X implementation callback:
  - Score unchanged at `85/86`.
  - Updated ownership wording so [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) is a shared/folded FunctionObjects invoke body used by this class's vtable slot, not an exclusively popup-owned body.
  - Preserved popup construction proof: vtable store `0x004980bc`, bound target `0x00498220`, zero adjustment, and captured pane pointer in the 24-byte callback object.
  - Added B010 current MCP session `279422f0` seven-vtable proof and retained the stale `0x004d0050` rejection.
- 2026-06-03 source-owner and autogen refinement:
  - What existed before: `COMPLETION:70`, `CONFIDENCE:80`, blank `RECONSTRUCTABLE`, and no `AUTOGEN_PARENT_UID`.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JO`.
  - Summary/evidence: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) now has `NexusTK/util/` pathing, `84/80` parent confidence, an explicit attachment policy for generated `FunctionObject*` instantiations, and a row for this popup-menu callback wrapper; [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) documents only the construction/consumer side. The exact invoke child [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) records the callback offsets, vtable/data-only xrefs, and stale `0x004d0050` rejection. Final C++ is still withheld under the active `90/90+` gate.
- 2026-06-06 A004 parent-gate cleanup:
  - Changed scores from `74/82` to `80/84`.
  - Removed stale recovered-source framing, added parent-gate status and score rationale, and narrowed `0x004d0050` to rejected stale metadata backed by IDA containment/xref checks.
  - Evidence: [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md), [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), and [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) support the shared callback-template ownership and popup-menu consumer split.
- Before: completion/confidence metadata were `0/0` despite the page documenting the popup-menu callback wrapper, confirmed invoke body, vtable/data xrefs, and rejected stale metadata.
- Changed to: `COMPLETION:70` and `CONFIDENCE:80`.
- Evidence: `0x0049af00-0x0049af11` is documented as the real invoke wrapper, while stale `0x004d0050` metadata is rejected; confidence remains medium-high because generated template naming is unwieldy and only the invoke method is active.
- 2026-06-14 Agent-A001 Goal 2 low-score repair:
  - Changed scores from `80/84` to `85/86`.
  - Added live IDA MCP confirmation of the invoke body, seven data xrefs, no direct callers, and the stale `0x004d0050` rejection. The exact child [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) now also clears `85/89`.
  - C++ remains blank below the active `90/90+` final-source gate.
