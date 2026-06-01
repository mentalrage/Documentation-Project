*** UID:0000V1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PacketBuffer Helpers

## Status

- Confidence: strong for helper behavior and broad utility role.
- Current Wave3 form: recovered global functions.
- Likely source module: [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- Main address docs: [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) and [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md)
- Evidence basis: recovered `simroot_v2` helper files, Wave3 xrefs, and IDA MCP lookup/xref checks on 2026-05-23.

## Responsibility

This helper family serializes and parses small packet fields. The common convention is big-endian integer order for multi-byte fields, cursor advancement for append/read helpers, and length-prefixed strings for text payloads.

## Helper Summary

| Address | Current Wave3 name | Behavior |
| --- | --- | --- |
| `0x00575380` | `WriteByteZ_575380` | Writes one byte and a trailing zero byte. |
| `0x005753a0` | `WriteUInt16BEZ_5753A0` | Writes a 16-bit value in big-endian order plus trailing zero. |
| `0x005753f0` | `WriteUInt32BEZ_5753F0` | Writes a 32-bit value in big-endian order plus trailing zero. |
| `0x00575480` | `ReadUInt16BE_575480` | Reads a big-endian 16-bit value. |
| `0x005754c0` | `ReadUInt32BE_5754C0` | Reads a big-endian 32-bit value. |
| `0x00575650` | `AppendByteZ_575650` | Writes one byte at `buffer + *writeOffset`, appends zero, advances by one. |
| `0x00575670` | `AppendUInt16BEZ_575670` | Appends a big-endian 16-bit value and advances by two. |
| `0x005756d0` | `AppendUInt32BEZ_5756D0` | Appends a big-endian 32-bit value and advances by four. |
| `0x00575710` | `ReadCursorByte_575710` | Reads one byte from `buffer + *readOffset` and advances by one. |
| `0x005757d0` | `AppendLengthPrefixedAnsi_5757D0` | Writes one-byte ANSI length and copies text bytes. |
| `0x00575850` | `PacketWriteWideString_575850` | Converts wide text to ANSI, writes one-byte length, and copies bytes. |
| `0x00575a90` | `PacketReadString_575A90` | Reads one-byte length and builds an `LObject` from the byte range. |
| `0x00575ac0` | `sub_575AC0` | Reads a two-byte big-endian length and builds/copies into an `LObject`-style string object. |
| `0x00575b50` | `sub_575B50` | Reads a two-byte big-endian length and copies that byte span into caller-provided storage. |

## Xref Weight

IDA MCP compact xref checks report:

- `WriteByteZ_575380`: 1114 code refs from 662 unique calling functions.
- `WriteUInt16BEZ_5753A0`: 222 refs from 163 unique functions.
- `WriteUInt32BEZ_5753F0`: 119 refs from 98 unique functions.
- `ReadUInt16BE_575480`: 372 refs from 143 unique functions.
- `ReadUInt32BE_5754C0`: 226 refs from 98 unique functions.

This caller spread is strong evidence for a shared packet utility module rather than ownership by one feature, UI pane, or socket method.

IDA MCP recheck on 2026-05-31 confirms exact function ranges for the listed scalar helpers, including `0x00575380-0x00575391`, `0x005753a0-0x005753b9`, `0x005753f0-0x00575419`, `0x00575480-0x0057549a`, `0x005754c0-0x005754e6`, `0x00575650-0x00575668`, `0x005757d0-0x00575810`, `0x00575a90-0x00575abb`, `0x00575ac0-0x00575b42`, and `0x00575b50-0x00575b8c`. The broad high-traffic helpers have hundreds to more than a thousand direct call sites, while the length-prefixed readers have narrow caller sets that still fit the packet-buffer utility role.

## Naming Notes

Wave3 recovered names include address suffixes. Existing generated call sites often use more natural names such as `PacketBufferWriteByte`, `PacketBufferWriteUInt16BE`, `PacketBufferWriteDwordBE`, `PacketBuffer_WriteByte`, or `PacketBufferWriteUInt32BE`. Final source cleanup should settle one convention and propagate it across call sites after owner placement is stable.

## Cross-References

- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md)
- [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the packet scalar helpers, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the helper family as rebuild-relevant packet-buffer code. Parent UID and C++ remain blank because final names and exact grouping with the canonical by-memory pages are not at the `95+` code gate.
  - Evidence: IDA MCP confirms exact helper ranges, no callees for core scalar read/write helpers, high xref weight for shared packet utility functions, and narrower length-prefixed string reader call sets.
