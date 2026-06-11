*** UID:0000U7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CheckBoxControlPane State Type Helper 00499EC0

## Status

- Entity kind: vtable-only method/helper.
- Address: `0x00499ec0-0x00499f0e`
- Likely source owner: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) or split candidate [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md).
- Autogen parent: [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md).
- Confidence: strong for behavior and vtable ownership; medium for final source-facing method name.
- Exact containing range: [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md).
- Exact vtable-data evidence: [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md), primary slot `0x00618520`.

## Behavior

The helper compares the stored control-state byte at `this + 0x103` against a requested type/state value.

- If the current byte differs and the requested value is checkbox control type id `20`, it first calls the primary vtable slot at `+0x20` with argument `0`.
- If the byte still differs, it stores the requested value at `+0x103` and calls the same vtable slot with `this + 0x44`, which matches the control client rectangle offset used by other pane refresh paths.
- If the byte already matches, it returns the existing value without side effects.

This looks like a control-state/type refresh helper rather than user-facing checkbox logic. The visible checkbox behavior remains the constructor, `SetChecked`, `GetChecked`, mouse toggle handler, and paint method documented in [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md).

## Evidence

- IDA MCP `lookup_funcs` on 2026-05-26 reports `0x00499ec0` as a real function of size `0x4e`.
- IDA MCP `xrefs_to 0x00499ec0` reports a single data xref from primary vtable slot `0x00618520`.
- IDA MCP `callers 0x00499ec0` reports no direct code callers, matching a vtable-only helper.
- [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md) confirms this slot belongs to the checkbox control family.
- [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md) confirms the exact primary/secondary/tertiary vtable-data child and records `0x00618520 -> 0x00499ec0`.
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) records this helper as the final method in the exact checkbox core, after `OnPaint` and before the next range.
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) records the neighboring `CheckBoxControlPane` scalar deleting destructor and `GetControlTypeId` return of type id `20`, matching this helper's special-case state value.

## Reconstruction Guidance

Keep this with the checkbox/control class implementation, but do not over-name it as a feature-specific method. During source rewrite, model it as a small virtual refresh/type-state helper until the inherited control virtual at slot `+0x20` receives a final semantic name.

## Cross-References

- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md)
- [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)
- [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md), and generated-omission wording was removed from the evidence basis.
  - Before: the vtable-only helper was unclassified and had stale generated-source caveat wording.
  - After: it is marked as source-level checkbox virtual/helper behavior under the validated CheckBoxControlPane split-candidate file root; C++ remains blank because the inherited slot name and final file split are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_499EC0` at `0x00499ec0`, size `0x4e`, no direct code callers, and vtable ownership already documented through [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md).

- 2026-05-30: Grading changed from `0/0` to `74/82`.
  - Before: page documented the vtable-only helper behavior, ownership, generated-source omission, and rewrite guidance but remained unevaluated.
  - After: score reflects documented state-byte/refresh behavior and vtable ownership, with lower completion/confidence because the inherited slot and final method name are still unresolved.
  - Evidence: IDA notes confirm the function size, single vtable data xref, and no direct callers.

- 2026-06-07 A009 evidence-link pass:
  - Before: score remained `74/82` and the page did not link the exact vtable-data child, checkbox layout, or destructor/type-id range.
  - After: score is `78/86`, with explicit links to the containing checkbox core, exact vtable-data child, layout, and destructor/control-type documentation.
  - Evidence: existing by-memory and by-type pages now cross-confirm the helper's primary vtable slot, containing range boundary, vtable-only dispatch surface, and type id `20` relationship while final method naming remains open.
