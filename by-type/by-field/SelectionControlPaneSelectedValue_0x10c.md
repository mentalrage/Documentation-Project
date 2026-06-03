*** UID:0001SV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000CR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelectionControlPane Selected Value Field 0x10c

## Status

- Confidence: strong for offset and use, medium for final source-level field name.
- Current entity kind: recovered field/layout note
- Likely owner: [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md)
- Likely source module: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Exact memory evidence: [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- Reconstructable: yes, as a source-level field/layout finding. Do not emit C++ until the full `SelectionControlPane` declaration and field name are proven.
- Parent: [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md), now attached to the validated [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) source family.

## Field Hypothesis

| Offset | Size | Meaning |
| --- | --- | --- |
| `+0x10c` | `4` | selected value, icon id, or frame id consumed by the control paint/refresh path |

## Evidence

- IDA MCP decompilation of `0x00495cb0` writes the incoming integer argument to `this[67]`, which is byte offset `+0x10c`.
- IDA MCP disassembly confirms the exact write as `mov [ecx+10Ch], eax`.
- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md) calls this helper for control id `12`, passing `37` or `48` to switch the pause/play control art.
- The helper immediately tail-calls vtable slot `+0x20` with argument `0`, so the stored value is expected to affect the next redraw/invalidation pass.
- 2026-05-31 IDA MCP recheck confirms the function body at `0x00495cb0-0x00495cc9`: `mov [ecx+10Ch], eax`, `mov [ebp+arg_0], 0`, then `jmp dword ptr [eax+20h]`.
- IDA MCP `callers` reports the known direct caller at `0x0052a1e2` inside `0x0052a180`; decompilation shows it retrieves control id `12` and passes `37` or `48` depending on the music-dialog toggle byte at offset `+620`.

## Open Questions

- Final field name remains provisional until the generic control paint/refresh consumers are fully documented.
- The field appears generic to `SelectionControlPane`, but current direct caller coverage is still narrow.

## Source-Layout Impact

This field should remain part of the generic selection/button-control layout. It is not a `MusicControlDialog` field even though the current known direct caller is the music dialog.

## Reconstruction Notes

- Marked as attached reconstructable field evidence because the exact write, caller context, and owning class are documented above the confidence threshold.
- `RECONSTRUCTION_CPP CODE` remains blank. The source-level field name is still provisional and should be emitted only with the final `SelectionControlPane` declaration.

## Cross-References

- [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md)
- [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)

## Changes

- 2026-06-03: Raised completion from `70` to `76` and attached parent [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md).
  - Evidence: [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) documents the exact `[ecx+0x10c]` write, caller, and redraw tail-call; the class page now has an attached [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) source-family parent.
