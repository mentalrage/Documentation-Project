*** UID:0000U7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CheckBoxControlPane State Type Helper 00499EC0

## Status

- Entity kind: vtable-only method/helper.
- Address: `0x00499ec0-0x00499f0e`
- Current Wave3 owner: [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md), but active generated source omits the body.
- Likely source owner: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) or split candidate [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md).
- Confidence: strong for behavior and vtable ownership; medium for final source-facing method name.

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
- Current active `source-3/simroot_v2/class_CheckBoxControlPane.cpp` omits this method even though [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md) confirm the slot.

## Reconstruction Guidance

Keep this with the checkbox/control class implementation, but do not over-name it as a feature-specific method. During source rewrite, model it as a small virtual refresh/type-state helper until the inherited control virtual at slot `+0x20` receives a final semantic name.

## Cross-References

- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `74/82`.
  - Before: page documented the vtable-only helper behavior, ownership, generated-source omission, and rewrite guidance but remained unevaluated.
  - After: score reflects documented state-byte/refresh behavior and vtable ownership, with lower completion/confidence because the inherited slot and final method name are still unresolved.
  - Evidence: IDA notes confirm the function size, single vtable data xref, no direct callers, and omission from active generated `CheckBoxControlPane` output.
