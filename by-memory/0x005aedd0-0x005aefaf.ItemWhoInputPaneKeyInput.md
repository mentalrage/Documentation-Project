*** UID:0002S2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x005aedd0-0x005aefaf ItemWhoInputPane Key Input

## Status

- Disposition: reconstructable NexusTK project code
- Entity kind: key-input method
- Owner: [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- Likely source module: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- Rebuild handling: source-authored, with adjacent compiler switch-table data
- Confidence: strong for IDA boundary, key behavior, saved-target effects, and packet dispatch; medium-high for final event/key names.

## Address Range

`0x005aedd0-0x005aefaf`, end-exclusive. IDA MCP `lookup_funcs 0x005aedd0` reports `sub_5AEDD0`, size `0x1df`.

The following `0x005aefaf-0x005af050` span is not a function. IDA disassembly labels it as alignment plus the key-handler jump/indirect tables (`jpt_5AEE1A` style switch support) before the mouse handler.

## Behavior

This method handles keyboard input while the item target prompt is active.

- Enter confirms the currently highlighted saved target when the event state byte is `8`, clears the highlight via [UID:0001L7][0x005af390-0x005af3af.ClearItemWhoTarget](by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md), sends [UID:0001LA][0x005af580-0x005af5ea.SendObjectActionPacket](by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md) with the stored item/action byte, and closes/forwards the input event through the line-input helper.
- Escape cancels the prompt and clears the saved target highlight when one exists.
- Previous/next navigation keys move through map-pane living-object targets using helper calls at `0x00506ae0`, `0x00506b30`, `0x00506b80`, and `0x00506bd0`, with modifier state selecting the traversal direction.
- A self/local-player key path selects `dword_67A748`.
- The method updates highlights with `0x0053b1b0` and stores the selected object id back to `dword_69BF24`.

## IDA MCP Evidence

- `lookup_funcs` confirms `0x005aedd0+0x1df`.
- `xrefs_to 0x005aedd0` reports vtable data ref `0x0062f2f4`.
- `callees 0x005aedd0` reports `0x005af390`, map traversal helpers `0x00506b30`, `0x00506b80`, `0x00506bd0`, `0x00506ae0`, lookup helper `0x00506970`, highlight helper `0x0053b1b0`, close/base input helper `0x004f25a0`, send helper `0x005af580`, and character narrowing helper `0x004a8b10`.
- `xrefs_to 0x0069bf24` reports key-handler reads/writes at `0x005aee27`, `0x005aee73`, `0x005aeeae`, `0x005aeeeb`, `0x005aef01`, `0x005aef44`, and `0x005aefa0`.
- Raw-byte review confirms the following `0x005aefaf-0x005af050` bytes are switch-table data and alignment, not another source function.

## Touched State

| Address or offset | Meaning | Evidence |
| --- | --- | --- |
| `this+0x108` | stored item/action byte | Used as the first argument to `0x005af580`. |
| event byte `a2+4` | event subtype/state gate | Enter/Escape/navigation cases only act when it equals `8`. |
| event flags `a2+0x10a` / narrowed key | modifier/key state | Used to choose switch cases and traversal direction. |
| `0x0069bf24` | saved item target id | Main selected-target state updated after traversal. |
| `0x0067a748` | local player fallback target | Self-target path and fallback target. |
| `0x0067a764` | map pane/global map object owner | Passed to lookup and traversal helpers. |

## Reconstruction Notes

Keep this as source-authored method code in the target-selection input pane module. Final C++ is intentionally blank until event struct fields, traversal helper names, and line-input close semantics are named at final-source confidence.

## Cross-References

- [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md)
- [UID:0001L6][0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md)
- [UID:0001L7][0x005af390-0x005af3af.ClearItemWhoTarget](by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md)
- [UID:0001LA][0x005af580-0x005af5ea.SendObjectActionPacket](by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md)

