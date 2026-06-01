*** UID:0001Y6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ModelessDialogPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md).
- Likely source file: [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md).
- Layout docs: [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md).
- Confidence: strong for vtable bases, constructor stores, method slots, and table extents.
- Verification: IDA MCP `list_globals`, `py_eval`, `xrefs_to`, `lookup_funcs`, and `disasm` checks on 2026-05-26. `wave3.py` was not executed for this pass.

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00618c48` | `0x004a07bd` | `+0x00` | Primary `DialogPane`/pane view for the modeless dialog object. |
| secondary | `0x00618ca8` | `0x004a07c4` | `+0xa0` | Event/input view passed to `EventDispatcher::AddToModalList`. |
| tertiary | `0x00618cd8` | `0x004a07ca` | `+0xa4` | Short event/update-handler view matching the common pane/DialogPane ABI. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00618c48` | `+0x00` | `0x0048c350` | Reused `DialogPane` scalar deleting destructor. `ModelessDialogPane` has no class-specific destructor body identified in this pass. |
| primary `0x00618c48` | `+0x30` | `0x0049dfd0` | Inherited dialog bounds/layout initialization virtual. |
| primary `0x00618c48` | `+0x3c` | `0x0049e190` | Inherited dialog show/list registration behavior. |
| primary `0x00618c48` | `+0x44` | `0x0049f090` | Inherited dialog focus/selection drawing virtual. |
| primary `0x00618c48` | `+0x50` | `0x0049f1d0` | Inherited dialog content drawing virtual. |
| primary `0x00618c48` | `+0x54` | `0x0049f2e0` | Inherited dialog border drawing virtual. |
| primary `0x00618c48` | `+0x58` | `0x0049fc00` | Inherited dialog hover/update virtual. |
| secondary `0x00618ca8` | `+0x00` | `0x0048c27b` | `DialogPane` secondary destructor adjustor thunk, subtracts `0xa0` then jumps to `0x0048c350`. |
| secondary `0x00618ca8` | `+0x04` | `0x004a0840` | `ModelessDialogPane::HandleMouseEvent`. |
| secondary `0x00618ca8` | `+0x08` | `0x004a0830` | `ModelessDialogPane::IsModal`, returns false. |
| secondary `0x00618ca8` | `+0x1c` | `0x004a89f0` | Shared dialog/event-support slot inherited from nearby dialog infrastructure. |
| tertiary `0x00618cd8` | `+0x00` | `0x0048c286` | `DialogPane` tertiary destructor adjustor thunk, subtracts `0xa4` then jumps to `0x0048c350`. |
| tertiary `0x00618cd8` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

The primary table ends before the secondary RTTI dword at `0x00618ca4`; the secondary table ends before the tertiary RTTI dword at `0x00618cd4`; the tertiary table ends before the neighboring data/string region at `0x00618ce0`. Do not treat `0x00618ce0` or following `DLGFRAME.*` string data as additional `ModelessDialogPane` virtual slots.

## IDA MCP Evidence

- `list_globals *ModelessDialogPane*` reports vtable bases at `0x00618c48`, `0x00618ca8`, and `0x00618cd8`, plus RTTI records at `0x006466d0`, `0x00646730`, and `0x00646744`.
- `xrefs_to` the three vtable bases reports constructor stores at `0x004a07bd`, `0x004a07c4`, and `0x004a07ca` inside `0x004a0760`.
- `xrefs_to 0x004a0840` reports the secondary-table data ref at `0x00618cac`; `xrefs_to 0x004a0830` reports the secondary-table data ref at `0x00618cb0`.
- `lookup_funcs` confirms `0x004a0760`, `0x004a0830`, `0x004a0840`, `0x0048c350`, `0x0048c27b`, and `0x0048c286` as function starts.
- `disasm` confirms the constructor writes the three vtables, then calls dialog bounds init `0x0049dfd0`, pane interaction init `0x00544d30`, and event-dispatcher registration `0x004a6fc0` with `this + 0xa0`.
- Current Wave3 metadata for `class_ModelessDialogPane.meta_wave3` reports `vtable_count: 0`, so the generated vtable inventory is incomplete despite active constructor code assigning the three symbolic vtables.
- 2026-05-31 IDA MCP recheck confirms the constructor stores the same three vtable bases and that secondary slots at `0x00618cac` and `0x00618cb0` point to `HandleMouseEvent` and `IsModal`. `get_u32` confirms `0x00618ca8` starts with `0x0048c27b`, followed by `0x004a0840` and `0x004a0830`; `0x00618cd8` starts with `0x0048c286`, followed by `0x00544e90`.

## Reconstruction Notes

Model `ModelessDialogPane` as a `DialogPane` subclass with the common three-vtable pane layout at `+0x00`, `+0xa0`, and `+0xa4`. Its class-specific behavior is concentrated in the constructor, `IsModal`, and secondary-table mouse-event handler. The handler's state accesses are secondary-view relative and map back to inherited `DialogPane` offsets, as recorded in [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md). The destructor slots are inherited `DialogPane` ABI support and should be linked to [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md), not reconstructed as standalone handwritten `ModelessDialogPane` methods.

## Cross-References

- [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md)
- [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md)
- [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md)
- [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md)
- [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## Changes

- Before: completion/confidence were `0/0`, and `RECONSTRUCTABLE` was blank despite the page containing IDA-backed vtable evidence.
- Changed to: completion `82`, confidence `88`, and `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: 2026-05-31 IDA MCP rechecked constructor stores, secondary virtual-method data references, and slot dwords for the secondary and tertiary tables. Scores remain below `95` because inherited primary-table slot naming is not yet fully audited.
