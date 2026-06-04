*** UID:0001UY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LineIteratorLayout

## Status

- Entity kind: inferred struct/layout
- Likely owner: [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) local helper or nearby text parsing helper
- Confidence: strong for runtime offsets and current binary behavior, low for final standalone header/file status.
- Evidence basis: read-only IDA MCP lookup/decompile/caller/xref/data-neighborhood checks on 2026-05-25, 2026-05-26, 2026-05-31, and 2026-06-04.

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

## Ownership Caveat

The exact original declaration form is not yet proven. The 16-byte runtime object is proven by both:

- IDA decompile of `0x004f3020`, which reads `this[1]`, `this[2]`, and `this[3]`.
- IDA decompile of `0x0056c0e0`, which stack-constructs four dwords: vtable, backing pointer, length, and zero offset.

Treat this as a source-relevant helper layout owned through [UID:0000KQ][LineIterator](by-file/LineIterator.md), while keeping final header/source placement unresolved.

## 2026-05-31 IDA Recheck

IDA MCP `lookup_funcs` confirms `sub_4F3020` size `0x40`, `sub_56C0E0` size `0x1fb`, `sub_573240` size `0x7`, and `sub_573540` size `0x24`. Current IDA decompile of `sub_56C0E0` writes `v13[0] = &LineIterator::vftable`, `v13[1] = a2`, `v13[2] = a3`, and `v13[3] = 0`, then calls `sub_4F3020(v13, ...)` at `0x0056c15b` and `0x0056c285`. Current IDA decompile of `sub_4F3020` reads the same `+0x04`, `+0x08`, and `+0x0c` fields and updates `+0x0c` while scanning for UTF-16 newline `0x000a`.

The layout is source-relevant and reconstructable, but no C++ declaration is emitted here yet because final placement and surrounding source shape remain below the 95+ autogen threshold.

## 2026-06-04 IDA Recheck

Live IDA MCP rechecked the same layout without using generated metadata: `sub_56C0E0` spans `0x0056c0e0-0x0056c2db` and writes `[ebp+var_34] = LineIterator::vftable`, `[ebp+var_30] = a2`, `[ebp+var_2c] = a3`, and `[ebp+var_28] = 0` before calling `sub_4F3020` at `0x0056c15b`. The second call at `0x0056c285` reuses the same stack object. `sub_4F3020` spans `0x004f3020-0x004f3060`, reads `+0x04`, `+0x08`, and `+0x0c`, and writes the advanced offset back to `+0x0c`.

## Cross-References

- [UID:000078][LineIterator](by-class/LineIterator.md)
- [UID:0000KQ][LineIterator](by-file/LineIterator.md)
- [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)
- [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md)
- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)

## Changes

- 2026-05-31 scoring and reconstructable classification:
  - What existed before: metadata was `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`, despite existing IDA-backed layout notes.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: current IDA MCP rechecked `sub_4F3020`, `sub_56C0E0`, destructor functions, callers, and the vtable neighborhood, proving the 16-byte runtime layout and source-relevant helper semantics. Scores remain below 95 because final source placement and complete original declaration form are not yet near-final.
- 2026-06-04 parent and evidence update:
  - What existed before: scored `80/88`, reconstructable, with blank `AUTOGEN_PARENT_UID`.
  - Changed to: scored `84/90` and attached to [UID:0000KQ][LineIterator](by-file/LineIterator.md).
  - Summary/evidence: live IDA MCP reverified the `sub_56C0E0` stack writes, both `sub_4F3020` calls, exact field reads/writes in `sub_4F3020`, and the 16-byte delete size in the scalar deleting destructor. Final C++ remains blank because original declaration and source placement are not 95+.
