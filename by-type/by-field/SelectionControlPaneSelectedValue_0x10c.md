*** UID:0001SV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// SelectionControlPane selected-value storage at +0x10c is declared by
// [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md) SelectionControlPane and written by [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
// SetSelectionAndRefresh. This field-evidence page has no standalone source
// object to emit.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SelectionControlPane Selected Value Field 0x10c

## Status

- Confidence: very strong for offset, caller-side values, and direct owner routing; medium-high for final source-level field name.
- Current entity kind: recovered field/layout note
- Likely owner: [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md)
- Likely source module: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Exact memory evidence: [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- Caller-side value evidence: [UID:0003ML][0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState](by-memory/0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState.md)
- Reconstructable: yes, as a source-level field/layout finding. Do not emit C++ until the full `SelectionControlPane` declaration and field name are proven.
- Parent: [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md), now at `85/87` and attached to the validated [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) source family.

## Field Hypothesis

| Offset | Size | Meaning |
| --- | --- | --- |
| `+0x10c` | `4` | selected value, icon id, or frame id consumed by the `SelectionControlPane` refresh/paint path |

Scope note: `+0x10c` is not a universal `ButtonControlPane` base field name. A 2026-06-13 C001 IDA listing search over `0x00494eb0-0x0049803a` found many `+0x10c` references in the button/choice-control family, including unrelated meanings such as `TextButtonExControlPane`'s text-provider child pointer. This page documents the `SelectionControlPane` field role proven by the exact setter at `0x00495cb0`, not every class that happens to reuse the same offset.

## Evidence

- IDA MCP decompilation of `0x00495cb0` writes the incoming integer argument to `this[67]`, which is byte offset `+0x10c`.
- IDA MCP disassembly confirms the exact write as `mov [ecx+10Ch], eax`.
- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md) calls this helper for control id `12`, passing `37` or `48` to switch the pause/play control art.
- The helper immediately tail-calls vtable slot `+0x20` with argument `0`, so the stored value is expected to affect the next redraw/invalidation pass.
- 2026-05-31 IDA MCP recheck confirms the function body at `0x00495cb0-0x00495cc9`: `mov [ecx+10Ch], eax`, `mov [ebp+arg_0], 0`, then `jmp dword ptr [eax+20h]`.
- IDA MCP `callers` reports the known direct caller at `0x0052a1e2` inside `0x0052a180`; decompilation shows it retrieves control id `12` and passes `37` or `48` depending on the music-dialog toggle byte at offset `+620`.
- 2026-06-13 C001 live IDA 9.1 MCP `lookup_funcs` confirms `sub_495CB0` at `0x00495cb0` has size `0x19`, the preceding `0x00495ca5` endpoint is not a function, and `sub_495CD0` starts at `0x00495cd0`.
- 2026-06-13 C001 MCP `analyze_function 0x00495cb0` reconfirms the one-basic-block body, the decompiler assignment `this[67] = a2`, the disassembly write `mov [ecx+10Ch], eax`, zero normal callees, and the sole caller `sub_52A180`.
- 2026-06-13 C001 MCP `analyze_function 0x0052a180` reconfirms the caller fetches control id `12` through `[this+0x1fc]` / vtable slot `+0x10`, loads `0x25` or `0x30`, and calls `sub_495CB0` at `0x0052a1e2`.
- 2026-06-13 C001 `int_convert.py` verified `0x25` is decimal `37` (Verified with int_convert.py), `0x30` is decimal `48` (Verified with int_convert.py), and `0x10c` is decimal `268` (Verified with int_convert.py).
- 2026-06-13 C001 byte-signature review of `0x00495ca5-0x00495cd0` shows eleven `0xcc` bytes before this helper, the exact eight-instruction body, then seven `0xcc` bytes before `sub_495CD0`.

## Open Questions

- Final source spelling remains provisional: `selectedValue`, `selectedFrameId`, or a nearby original name are all still possible.
- No constructor or dedicated vtable block has been proven for a standalone `SelectionControlPane` declaration; the class remains a small helper/declaration inside the button/choice-control source family.

## Source-Layout Impact

This field should remain part of the generic selection/button-control layout. It is not a `MusicControlDialog` field even though the current known direct caller is the music dialog.

The direct parent remains [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md), not [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), because this page is a field-level claim for the tiny `SelectionControlPane` helper. `ButtonControlPane` remains the source-module parent through the class page.

## Reconstruction Notes

- Marked as attached reconstructable field evidence because the exact write, caller context, and owning class are documented above the confidence threshold.
- `RECONSTRUCTION_CPP CODE` now contains a formal no-code field-evidence comment. The field itself emits through [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md) as `m_selectedValue`; this page should not emit a duplicate standalone source object.
- Score rationale: `86/90` is justified by exact live IDA function boundaries, instruction-level write evidence, caller-side value flow, verified constants, direct parent at `85/87`, and the explicit offset-reuse caveat. Completion stays below final-source level because final field spelling, declaration placement, and virtual slot name remain unresolved.

## Cross-References

- [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md)
- [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- [UID:0003ML][0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState](by-memory/0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState.md)

## Changes

- 2026-06-03: Raised completion from `70` to `76` and attached parent [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md).
  - Evidence: [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) documents the exact `[ecx+0x10c]` write, caller, and redraw tail-call; the class page now has an attached [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) source-family parent.
- 2026-06-13 C001 type-quality pass:
  - Raised from `76/86` to `86/90`.
  - Evidence: live IDA 9.1 MCP reconfirmed the `0x00495cb0-0x00495cc9` helper body, sole caller at `0x0052a1e2`, caller-side `0x25`/`0x30` selected frame values, alignment on both sides, and local `+0x10c` reuse caveats across the button/choice-control neighborhood. Direct parent [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md) now clears `85/87`; [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) was already `86/88`. C++ remains blank below the final-source gate.
