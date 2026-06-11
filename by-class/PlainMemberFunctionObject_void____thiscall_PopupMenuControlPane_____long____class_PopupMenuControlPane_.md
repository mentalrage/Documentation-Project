*** UID:0000AK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_

## Status

- Confidence: strong for popup-menu callback wrapper role.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support, instantiated by [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md).
- Autogen source owner: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) under `NexusTK/util/`; [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) remains the popup-menu construction and consumer owner.
- Short item alias: [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)
- Memory documentation: [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md)
- Parent gate: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) is above `80/80`, and this class page now clears the child-side threshold for source-family attachment.

## Class Purpose

This compiler-emitted callback wrapper dispatches a popup-menu selection value to a `PopupMenuControlPane` member callback. The generated template spelling is unwieldy, so use `PopupMenuSelectionCallback` in feature docs when a short alias is clearer.

## Source Ownership And Autogen

- Rebuild handling: source-declared/generated-binary. The reusable callback template/type declaration must be available to the rebuilt project, while the exact vtable/function bytes should be emitted by the compiler from the template/source declaration.
- Parent attachment: this class attaches to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), whose documented policy permits high-confidence generated `FunctionObject*` instantiations that describe reusable callback support.
- Feature ownership caveat: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) owns allocation, configuration, and use of this callback for popup menu selection; it does not own the reusable callback type itself.
- Exact source-bearing child: [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md).
- Final C++ remains blank because the exact original template declaration/source spelling is still below the 95+ reconstruction-code gate.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Invoke` | `0x0049af00-0x0049af11` | Reads the stored callback and target/adjustment fields, then calls the target with the computed selection value. |

## Rejected Stale Metadata

Stale auxiliary metadata lists a `NoOp` method at `0x004d0050`, but IDA MCP `lookup_funcs` on 2026-05-25 resolves that address inside `sub_4CFFB0` (`0x004cffb0-0x004d006f`) rather than as a standalone no-op callback method. Do not treat `0x004d0050` as confirmed ownership for this class unless live IDA evidence later proves a standalone function there.

2026-05-25 current-state recheck: IDA `xrefs_to 0x004d0050` reports only the internal code xref at `0x004d004e` inside `sub_4CFFB0`; this remains a metadata issue, not a confirmed wrapper method.

## Evidence Notes

- IDA `lookup_funcs 0x0049af00` confirms a real `0x11` byte function.
- IDA `xrefs_to 0x0049af00` reports data references from several vtable-like slots, consistent with a virtual callback object.
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) already owns the feature allocation/consumer side.
- [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) records live IDA confirmation of the exact invoke span, no direct code callers, seven callback-table slots, the adjusted member-function dispatch body, and the stale `0x004d0050` rejection.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `80` | The page now records the popup-menu callback wrapper role, FunctionObjects/PopupMenuControls ownership split, exact invoke child, parent gate, stale metadata rejection, source-declared/generated-binary rebuild handling, and final C++ blocker. It remains below higher completion because final template declaration spelling, full construction-site coverage, and original header/source split remain open. |
| Confidence | `84` | IDA-confirmed invoke bounds/xrefs, the exact memory child, PopupMenuControls consumer evidence, and FunctionObjects attachment policy strongly support the interpretation. Confidence remains capped because the long generated template spelling and final source declaration shape are not yet source-final. |

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)
- [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md)
- [UID:0000AN][PopupMenuControlPane](by-class/PopupMenuControlPane.md)

## Changes

- 2026-06-03 source-owner and autogen refinement:
  - What existed before: `COMPLETION:70`, `CONFIDENCE:80`, blank `RECONSTRUCTABLE`, and no `AUTOGEN_PARENT_UID`.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JO`.
  - Summary/evidence: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) now has `NexusTK/util/` pathing, `84/80` parent confidence, an explicit attachment policy for generated `FunctionObject*` instantiations, and a row for this popup-menu callback wrapper; [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) documents only the construction/consumer side. The exact invoke child [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) records the callback offsets, vtable/data-only xrefs, and stale `0x004d0050` rejection. Final C++ is still withheld under the 95+ gate.
- 2026-06-06 A004 parent-gate cleanup:
  - Changed scores from `74/82` to `80/84`.
  - Removed stale recovered-source framing, added parent-gate status and score rationale, and narrowed `0x004d0050` to rejected stale metadata backed by IDA containment/xref checks.
  - Evidence: [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md), [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), and [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) support the shared callback-template ownership and popup-menu consumer split.
- Before: completion/confidence metadata were `0/0` despite the page documenting the popup-menu callback wrapper, confirmed invoke body, vtable/data xrefs, and rejected stale metadata.
- Changed to: `COMPLETION:70` and `CONFIDENCE:80`.
- Evidence: `0x0049af00-0x0049af11` is documented as the real invoke wrapper, while stale `0x004d0050` metadata is rejected; confidence remains medium-high because generated template naming is unwieldy and only the invoke method is active.
