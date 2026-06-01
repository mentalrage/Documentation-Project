*** UID:0001WH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VoteMenuPane Layout

## Status

- Confidence: strong for the documented tail fields, vtable offsets, and state-byte use from IDA/MCP evidence. Final C++ layout names remain below the final-source gate.
- Evidence basis: IDA MCP raw constructor disassembly, decompilation of `VoteMenuPane` methods, vtable xrefs, and exact child function evidence. Wave3/simroot output is only a lead and is not used as authority here.

## Layout Summary

`VoteMenuPane` is a `Pane`-derived menu popup with three vtable pointers and a compact state tail.

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `Pane` base / primary vtable | Primary pane/menu object; constructor stores `0x00622ff8`. |
| `+0xa0` | secondary vtable | Secondary inherited subobject used by destructor thunks; constructor stores `0x0062304c`. |
| `+0xa4` | tertiary vtable | Tertiary inherited subobject used by destructor thunks; constructor stores `0x0062307c`. |
| `+0xf8` | `uint8` | Pressed/selected flag used while clicking a vote row; constructor initializes to `0`. |
| `+0xf9` | `uint8` | Highlighted row index, `0xff` when no row is selected. |
| `+0xfc` | `uint32` | Vote type or mode argument from constructor. |
| `+0x100` | `wchar_t[0x21]` | Target player name copied by constructor. |

## Notes

- IDA decompilation of virtual handlers sometimes presents `this` as a secondary-base pointer, causing offsets such as `this + 88` and `this - 160`. The table above is normalized to the object base used by the constructor.
- Keep the two state bytes separate. [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md) initializes `+0xf8` and `+0xf9` separately; [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md) and [UID:0002LU][0x00555af0-0x00555c68.VoteMenuPaneOnPaint](by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md) consume them as distinct flags.
- See [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md) for IDA-confirmed table bases, slot ownership, and RTTI/string boundary warnings.

## IDA Evidence

- IDA MCP `disasm` on 2026-05-31 shows the raw constructor storing vtables at `+0x00`, `+0xa0`, and `+0xa4`, clearing `+0xf8`, storing the constructor vote-type argument at `+0xfc`, setting `+0xf9` to `0xff`, and copying the target name to `+0x100` with `_wcscpy_s` size `0x21`.
- IDA MCP `decompile` on 2026-05-31 shows [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md) reading/writing the normalized `+0xf8/+0xf9` state bytes and using the normalized target-name buffer at `+0x100` for the submit helper.
- IDA MCP `decompile` on 2026-05-31 shows [UID:0002LU][0x00555af0-0x00555c68.VoteMenuPaneOnPaint](by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md) reading `this[249]` and `this[248]`, which normalize to `+0xf9` and `+0xf8`.
- IDA MCP `xrefs_to` on 2026-05-31 confirms the three vtable bases are written by the raw constructor, non-deleting destructor, and scalar deleting destructor.

## Cross-References

- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md)
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
- [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md)
- [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md)
- [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md)
- [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md)
- [UID:0002LU][0x00555af0-0x00555c68.VoteMenuPaneOnPaint](by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md)
- [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)

## Changes

- 2026-05-31 IDA-based layout verification:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and evidence text that included Wave3 metadata as part of the basis.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and IDA/MCP-only evidence for the layout fields.
  - Summary/evidence: IDA MCP raw constructor disassembly, decompilation of mouse/paint handlers, and vtable xrefs confirm the documented offsets; generated Wave3/simroot output remains only a lead and not a confidence source.
