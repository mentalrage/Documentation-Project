*** UID:0000V1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PacketBuffer Helpers

## Status

- Confidence: strong for helper behavior, shared utility role, and PacketBuffer parent placement; medium-high for final source names and exact signatures.
- Parent attachment: attached to [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md), whose current confidence is `82`.
- Main address docs: [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) and [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md)
- Evidence basis: live IDA MCP lookup, decompilation, callee, and xref checks on 2026-06-04.
- Reconstruction note: C++ intentionally remains blank because final source names, cursor/storage types, and the mixed helper island are not at the `95/95` gate.

## Responsibility

This helper family serializes and parses small packet fields. The common convention is big-endian integer order for multi-byte fields, cursor advancement for append/read helpers, and length-prefixed strings for text payloads.

## Helper Summary

| Range | Current IDA name | Behavior |
| --- | --- | --- |
| `0x00575380-0x00575391` | `sub_575380` | Writes one byte and a trailing zero byte. |
| `0x005753a0-0x005753b9` | `sub_5753A0` | Writes a 16-bit value in big-endian order plus trailing zero. |
| `0x005753c0-0x005753e1` | `sub_5753C0` | Writes the high/middle/low bytes of a 24-bit-style value into a four-byte slot. |
| `0x005753f0-0x00575419` | `sub_5753F0` | Writes a 32-bit value in big-endian order plus trailing zero. |
| `0x00575420-0x00575470` | `sub_575420` | Writes a 64-bit value in big-endian order plus trailing zero. |
| `0x00575470-0x0057547a` | `std::_Narrow_char_traits<char,int>::to_char_type` | Adjacent STL/runtime helper; not PacketBuffer-owned source logic. |
| `0x00575480-0x0057549a` | `sub_575480` | Reads a big-endian 16-bit value. |
| `0x005754c0-0x005754e6` | `sub_5754C0` | Reads a big-endian 32-bit value. |
| `0x005754f0-0x00575574` | `sub_5754F0` | Reads a big-endian 64-bit value. |
| `0x00575580-0x0057561a` | `sub_575580` | Converts a wide hostname to ANSI, resolves it with `gethostbyname`, and copies four address bytes. |
| `0x00575650-0x00575668` | `sub_575650` | Cursor append of one byte plus trailing zero, advancing by one. |
| `0x00575670-0x00575693` | `sub_575670` | Cursor append of a big-endian 16-bit value plus trailing zero, advancing by two. |
| `0x005756d0-0x00575703` | `sub_5756D0` | Cursor append of a big-endian 32-bit value plus trailing zero, advancing by four. |
| `0x00575710-0x00575723` | `sub_575710` | Cursor read of one byte, advancing by one. |
| `0x00575730-0x0057575d` | `sub_575730` | Cursor read of a big-endian 16-bit value, advancing by two. |
| `0x00575790-0x005757c8` | `sub_575790` | Cursor read of a big-endian 32-bit value, advancing by four. |
| `0x005757d0-0x00575810` | `sub_5757D0` | Writes one-byte ANSI length and copies text bytes. |
| `0x00575850-0x005758db` | `sub_575850` | Converts wide text to ANSI, writes one-byte length, and copies bytes. |
| `0x00575970-0x00575a07` | `sub_575970` | Converts wide text to ANSI, writes a two-byte big-endian length, and copies bytes; live IDA reports no direct code refs. |
| `0x00575a10-0x00575a81` | `sub_575A10` | Reads one-byte length, copies the byte span into a temporary string object, and transfers it to caller storage. |
| `0x00575a90-0x00575abb` | `sub_575A90` | Reads one-byte length and copies the byte span into caller-provided storage. |
| `0x00575ac0-0x00575b42` | `sub_575AC0` | Reads a two-byte big-endian length and builds/copies into an `LObject`-style string object. |
| `0x00575b50-0x00575b8c` | `sub_575B50` | Reads a two-byte big-endian length and copies that byte span into caller-provided storage. |

## Xref Weight

Live IDA MCP compact xref checks report:

- `sub_575380`: 1114 direct code refs from 178 caller functions.
- `sub_5753A0`: 222 direct code refs from 61 caller functions.
- `sub_5753F0`: 119 direct code refs from 49 caller functions.
- `sub_575480`: 372 direct code refs from 96 caller functions.
- `sub_5754C0`: 226 direct code refs from 70 caller functions.

This caller spread is strong evidence for a shared packet utility module rather than ownership by one feature, UI pane, or socket method.

IDA MCP recheck on 2026-06-04 confirms 21 functions in `0x00575380-0x00575abb` plus the two length-prefixed readers in `0x00575ac0-0x00575b8c`. The broad high-traffic helpers have hundreds to more than a thousand direct call sites, while the narrow string/64-bit variants still fit the packet-buffer utility role. The embedded `std::_Narrow_char_traits<char,int>::to_char_type` runtime helper is explicitly excluded from PacketBuffer source ownership even though it lies inside the address island.

## Naming Notes

Current names are still IDA fallback names. Final source cleanup should settle one convention such as `PacketBufferWriteByte`, `PacketBufferWriteUInt16BE`, `PacketBufferWriteDwordBE`, `PacketBufferReadUInt16BE`, or shorter internal names after call-site types are stable.

## Cross-References

- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md)
- [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)

## Changes

- 2026-06-04: Raised from `70/85` to `82/88` and attached to [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md).
  - Before: the page covered the main scalar helpers, but it omitted live functions inside the island, left parent attachment blank, and mixed in stale provenance.
  - After: the page records the complete live IDA function inventory for the helper island, separates the embedded STL/runtime helper from PacketBuffer source ownership, documents 24-bit/64-bit/cursor/string variants, and records why parent attachment is now justified.
  - Evidence: live IDA MCP `py_eval` function enumeration and xrefs, batched decompilation for `0x5753c0`, `0x575420`, `0x5754f0`, `0x575580`, `0x575730`, `0x575790`, `0x575970`, and `0x575a10`, plus existing [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) confidence `82`.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the packet scalar helpers, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the helper family as rebuild-relevant packet-buffer code. Parent UID and C++ remain blank because final names and exact grouping with the canonical by-memory pages are not at the `95+` code gate.
  - Evidence: IDA MCP confirms exact helper ranges, no callees for core scalar read/write helpers, high xref weight for shared packet utility functions, and narrower length-prefixed string reader call sets.
