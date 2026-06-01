*** UID:0001UY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LineIteratorLayout

## Status

- Entity kind: inferred struct/layout
- Current Wave3 struct id: `LineIterator`
- Likely owner: [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) local helper or nearby text parsing helper
- Confidence: strong for runtime offsets and current binary behavior, low for final standalone header/file status.
- Evidence basis: read-only IDA MCP lookup/decompile/caller/xref/data-neighborhood checks on 2026-05-25, 2026-05-26, and 2026-05-31. `simroot_v2` is only a generated-data caveat source here, not authority.

## Layout

```text
LineIterator
  +0x00  void** vtable              // one-slot vtable at 0x00624784
  +0x04  const wchar_t* data         // backing UTF-16 buffer
  +0x08  uint32_t lengthChars        // buffer length in wide characters
  +0x0c  uint32_t offsetChars        // current scan offset in wide characters
```

Observed object size is `0x10` bytes. IDA decompilation of [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) models the stack iterator as `_DWORD v13[4]` and initializes all four dwords before calling [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md).

## Behavior

[UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md) reads `offsetChars`, `data`, and `lengthChars`, scans UTF-16 characters until `0x000a` or the end of the buffer, stores the advanced offset back to `+0x0c`, and constructs a string from the previous cursor to the new cursor.

If a newline is present, the stored offset is advanced after reading it. The constructed end pointer is therefore after the newline character; any delimiter stripping or empty-line decision belongs to the downstream string helpers in the parser, not to the iterator layout itself.

## Wave3 Data Caveat

Current `source-3/simroot_v2/class_LineIterator.meta_wave3` derives a Ghidra struct size of only `4` bytes with one `vftptr_0x0` field. That is incomplete for the real runtime object. The missing fields are proven by both:

- IDA decompile of `0x004f3020`, which reads `this[1]`, `this[2]`, and `this[3]`.
- IDA decompile of `0x0056c0e0`, which stack-constructs four dwords: vtable, backing pointer, length, and zero offset.

Do not use the current 4-byte Wave3 struct as source-layout evidence. Treat it as a generated-data issue until Wave3 materializes `ReadNextLine` and the full iterator layout.

## 2026-05-31 IDA Recheck

IDA MCP `lookup_funcs` confirms `sub_4F3020` size `0x40`, `sub_56C0E0` size `0x1fb`, `sub_573240` size `0x7`, and `sub_573540` size `0x24`. Current IDA decompile of `sub_56C0E0` writes `v13[0] = &LineIterator::vftable`, `v13[1] = a2`, `v13[2] = a3`, and `v13[3] = 0`, then calls `sub_4F3020(v13, ...)` at `0x0056c15b` and `0x0056c285`. Current IDA decompile of `sub_4F3020` reads the same `+0x04`, `+0x08`, and `+0x0c` fields and updates `+0x0c` while scanning for UTF-16 newline `0x000a`.

The layout is source-relevant and reconstructable, but no C++ declaration is emitted here yet because final placement and surrounding source shape remain below the 95+ autogen threshold.

## Cross-References

- [UID:000078][LineIterator](by-class/LineIterator.md)
- [UID:0000KQ][LineIterator](by-file/LineIterator.md)
- [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)
- [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md)
- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-05-31 scoring and reconstructable classification:
  - What existed before: metadata was `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`, despite existing IDA-backed layout notes.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: current IDA MCP rechecked `sub_4F3020`, `sub_56C0E0`, destructor functions, callers, and the vtable neighborhood, proving the 16-byte runtime layout and source-relevant helper semantics. Scores remain below 95 because final source placement and complete original declaration form are not yet near-final.
