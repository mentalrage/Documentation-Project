*** UID:0001UY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000078 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LineIteratorLayout

## Status

- Entity kind: non-emitting class-layout support; the complete source declaration exists on [UID:000078][LineIterator](by-class/LineIterator.md).
- Direct owner: UID000078, emitted through [UID:0000NZ][SpelledPane](by-file/SpelledPane.md); [UID:0000KQ][LineIterator](by-file/LineIterator.md) is a reviewed non-source historical index.
- Confidence: very strong for runtime offsets, current binary behavior, source-facing field types, exact object size, and sole declaration ownership; exact private-header/source-local token placement remains inferred.
- Evidence basis: read-only IDA MCP lookup/decompile/caller/xref/data-neighborhood checks on 2026-05-25, 2026-05-26, 2026-05-31, 2026-06-04, and 2026-06-12.

## Layout

```text
LineIterator
  +0x00  void** vtable              // one-slot vtable at 0x00624784
  +0x04  const wchar_t* m_text       // inferred backing UTF-16 buffer
  +0x08  uint32_t m_length           // inferred buffer length in wide characters
  +0x0c  uint32_t m_offset           // inferred current scan offset in wide characters
```

Observed object size is `0x10` / 16 bytes (Verified with int_convert.py). IDA decompilation of [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) models the stack iterator as `_DWORD v13[4]` and initializes all four dwords before calling [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md). The `m_text`, `m_length`, and `m_offset` names are source-facing inferences from field roles and are not symbol-proofed original names.

## Behavior

[UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md) reads `m_offset`, `m_text`, and `m_length`, scans UTF-16 characters until `0x000a` or the end of the buffer, stores the advanced offset back to `+0x0c`, and constructs a string from the previous cursor to the new cursor.

If a newline is present, the stored offset is advanced after reading it. The constructed end pointer is therefore after the newline character; any delimiter stripping or empty-line decision belongs to the downstream string helpers in the parser, not to the iterator layout itself.

## Source Declaration Ownership

The exact 16-byte runtime object is proven by both:

- IDA decompile of `0x004f3020`, which reads `this[1]`, `this[2]`, and `this[3]`.
- IDA decompile of `0x0056c0e0`, which stack-constructs four dwords: vtable, backing pointer, length, and zero offset.

Treat this page as non-emitting support owned by [UID:000078][LineIterator](by-class/LineIterator.md). The complete class declaration on UID000078 is the sole human source declaration and emits through SpelledPane. Exact private-header versus source-local placement remains a confidence caveat, not a duplicate struct or blank-code blocker.

## 2026-05-31 IDA Recheck

IDA MCP `lookup_funcs` confirms `sub_4F3020` size `0x40`, `sub_56C0E0` size `0x1fb`, `sub_573240` size `0x7`, and `sub_573540` size `0x24`. Current IDA decompile of `sub_56C0E0` writes `v13[0] = &LineIterator::vftable`, `v13[1] = a2`, `v13[2] = a3`, and `v13[3] = 0`, then calls `sub_4F3020(v13, ...)` at `0x0056c15b` and `0x0056c285`. Current IDA decompile of `sub_4F3020` reads the same `+0x04`, `+0x08`, and `+0x0c` fields and updates `+0x0c` while scanning for UTF-16 newline `0x000a`.

The historical conclusion that this page itself was source-relevant and reconstructable is superseded by the 2026-07-15 class audit: the exact layout remains evidence, while UID000078 alone emits the complete declaration.

## 2026-06-04 IDA Recheck

Live IDA MCP rechecked the same layout without using generated metadata: `sub_56C0E0` spans `0x0056c0e0-0x0056c2db` and writes `[ebp+var_34] = LineIterator::vftable`, `[ebp+var_30] = a2`, `[ebp+var_2c] = a3`, and `[ebp+var_28] = 0` before calling `sub_4F3020` at `0x0056c15b`. The second call at `0x0056c285` reuses the same stack object. `sub_4F3020` spans `0x004f3020-0x004f3060`, reads `+0x04`, `+0x08`, and `+0x0c`, and writes the advanced offset back to `+0x0c`.

## 2026-06-12 IDA Recheck

Agent-A004 Batch 272 live IDA MCP reconfirmed the stack layout around `0x0056c130-0x0056c15b`: `[ebp+var_34]` receives `??_7LineIterator@@6B@`, `[ebp+var_30]` receives the backing pointer, `[ebp+var_2c]` receives the length, and `[ebp+var_28]` receives zero before the first `sub_4F3020` call. `xrefs_to 0x004f3020` still has only the two `sub_56C0E0` calls at `0x0056c15b` and `0x0056c285`. The field offsets `+0x04`, `+0x08`, and `+0x0c` remain the only observed state fields; `0x0c` is 12 decimal (Verified with int_convert.py).

## 2026-07-07 B011 Source-Quality Sync

Accepted B011 MCP session `43ccf853` reconfirmed the same stack setup at `0x0056c133-0x0056c146`, target body reads/writes at offsets `+0x04`, `+0x08`, and `+0x0c`, the two-only `ReadNextLine` parser callers, and the `0x10` / 16-byte scalar-deleting-destructor object size (Verified with int_convert.py). The layout records source-facing inferred field names `m_text`, `m_length`, and `m_offset` because those names match the accepted UID000190 first-draft C++ and exact field roles. The later direct destructor/class audit resolves sole declaration ownership on UID000078 while retaining this page as non-emitting support.

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
  - Summary/evidence: live IDA MCP reverified the `sub_56C0E0` stack writes, both `sub_4F3020` calls, exact field reads/writes in `sub_4F3020`, and the 16-byte delete size in the scalar deleting destructor. At that time, original declaration and source placement were treated as a blank-C++ blocker; the 2026-07-07 B011 callback supersedes that blocker for UID000190, while this layout page still avoids emitting a full declaration.
- 2026-06-12 Agent-A004 Batch 272 layout gate update:
  - What existed before: scored `84/90` with the correct layout but below the current 85 completion threshold.
  - Changed to: scored `85/91`.
  - Summary/evidence: live IDA MCP reverified the stack writes, two-only `ReadNextLine` caller set, concrete field offsets, one-slot vtable, and `0x10` object size; int_convert.py verified the referenced sizes/offsets.
- 2026-07-07 Agent-B011 UID000190 callback:
  - What existed before: scored `85/91` and used generic `data`, `lengthChars`, and `offsetChars` source-facing field names.
  - Changed to: scored `86/92` and records inferred `m_text`, `m_length`, and `m_offset` names used by UID000190 first-draft C++.
  - Summary/evidence: accepted B011 report used MCP session `43ccf853` to reconfirm parser stack setup, exact target field accesses, two-only caller set, and 16-byte object size. Final declaration/header placement remains open.

## 2026-07-15 B003 UID0001HL Non-Emitting Layout Callback

- Current metadata is `91/94`, direct owner UID000078, `RECONSTRUCTABLE:FALSE`, blank emitter/position, and blank formal C++. This is a deliberate duplicate-declaration exclusion, not a loss of the exact layout evidence.
- UID000078 now declares one polymorphic 16-byte class: compiler vptr at `+0x00`, `const wchar_t *m_text` at `+0x04`, `unsigned int m_length` at `+0x08`, and `unsigned int m_offset` at `+0x0c`.
- Parser writes prove backing pointer, length, and zero offset; UID000190 proves unsigned length/offset comparisons and cursor updates; UID0001HO's 16-byte allocation-release argument independently proves complete object size.
- Self-only RTTI proves no base subobject. The four x86 dwords consume the complete size, so there is no additional member or tail padding to invent.
- Source-facing member names remain high-probability inferred names rather than symbol proof. `unsigned int` is preferred over signed fields because the scanner uses unsigned bounds; a raw aggregate is rejected because the object is polymorphic.
- UID000078 contains the sole class declaration and exact inline constructor/destructor. This page must not emit a second struct, explicit vptr member, raw offset overlay, scalar-delete flag, RTTI/vtable arrays, EH/cookie code, raw addresses, or decompiler artifacts.
- Historical standalone-route and unresolved-declaration wording above is preserved as provenance but superseded by the complete class and SpelledPane route.
