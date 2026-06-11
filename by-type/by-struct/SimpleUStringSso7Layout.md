*** UID:0001W5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000D9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleUStringSso7Layout

## Status

- Entity kind: inferred struct/layout
- Direct owner: [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- File parent through class: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Proposed header: `util/StringUtil.h`
- Confidence: strong for the 24-byte SSO-7 layout in the two endpoint helpers and for the `SimpleUString` class parent; medium-high for how this public string facade relates to the later pointer-backed family.
- Reconstructable: true as a source-level string-layout declaration; C++ body remains blank because the final original class/template relationship is still unresolved.

## Direct Parent Decision

`AUTOGEN_PARENT_UID` is set to [UID:0000D9][SimpleUString](by-class/SimpleUString.md). The child layout now clears the corrected `85/85` gate, and Batch140 raised the class parent to `85/87` with SSO-specific parent evidence. The direct owner is the `SimpleUString` class/facade page because this is an object layout with class methods at `0x00421310` and `0x00421590`; the broader file parent remains [UID:0000OB][StringUtil](by-file/StringUtil.md). Do not attach this SSO layout directly to [UID:0000OA][StringBase](by-file/StringBase.md), which owns the separate pointer-backed ref-counted layout.

## Layout Hypothesis

The early `SimpleUString` helper pair uses a 24-byte UTF-16 small-string layout with inline space for seven characters plus terminator:

| Offset | Size | Field | Notes |
| --- | --- | --- | --- |
| `0x00` | `0x10` | `heapBuffer` or `inlineBuffer[8]` | Inline buffer is used when capacity is `<= 7`; otherwise first dword is a heap pointer. |
| `0x10` | `0x04` | `length` | Counted wide characters, excluding terminator. |
| `0x14` | `0x04` | `capacity` | Inline capacity is `7`; heap capacity uses growth heuristics. |

## Evidence

- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) frees `heapBuffer` only when `capacity > 7`, then writes `length = 0`, `capacity = 7`, and `inlineBuffer[0] = 0`.
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) copies a counted wide buffer either into inline storage or newly allocated heap storage and preserves a NUL terminator.
- The historical [UID:0000WT][0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland](by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md) aggregate is mixed; the middle functions are not layout evidence for this struct.
- Metadata explicitly calls this the UTF-16 SSO-7 subcluster.
- 2026-06-08 Batch140 live IDA refresh reconfirmed `0x00421310` as `sub_421310` size `0x52` and `0x00421590` as `sub_421590` size `0x13b`. The clear helper still calls the allocator-free path plus invalid-parameter support, while the assign helper still calls allocation, `memmove`, string-too-long support, free, and invalid-parameter support.

## Operational Model

- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) treats `+0x14` as the capacity gate. Values below `8` mean the object starts with inline UTF-16 storage; values `>= 8` mean `+0x00` is a heap pointer that must be released before resetting to the empty inline state.
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) treats `+0x10` as the current length, compares the requested counted UTF-16 length against `+0x14`, writes the terminator after `length` code units, and uses the same heap/inline split when growing.
- The growth path rounds the requested length with an `| 7` style capacity floor and checks a 1.5x growth candidate before allocating `(capacity + 1) * sizeof(wchar_t)` bytes. That confirms the capacity is counted in UTF-16 code units, not raw bytes.
- Large heap strings use an aligned-allocation header validation path before free. That behavior belongs to the storage helper policy; it does not add fields inside this 24-byte object.

## Static Instance Evidence

[UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md) is a concrete static object with the same empty SSO shape:

| Range | Layout role |
| --- | --- |
| `0x0066de18-0x0066de28` | zeroed inline storage / pointer-or-inline union |
| `0x0066de28-0x0066de2c` | length field initialized to `0` |
| `0x0066de2c-0x0066de30` | capacity field initialized to `7` |

That page keeps ownership under MetaMan because the object is used as metadata lookup state, but its initialized bytes match this layout's empty inline representation.

## Boundary Against Pointer-Backed Strings

- Keep this layout separate from [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md) and [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md). The SSO-7 object embeds its short UTF-16 buffer in the first 16 bytes and stores length/capacity at `+0x10/+0x14`; the pointer-backed family stores a data pointer to a ref-counted header at `data[-3..-1]`.
- [UID:0000D9][SimpleUString](by-class/SimpleUString.md) and [UID:0000OB][StringUtil](by-file/StringUtil.md) currently use this page as the SSO-side layout anchor while leaving the final public API and `StringBase` split unresolved.

## Open Questions

- Whether this is the same public string facade as the pointer-backed helpers around `0x00583210`, or a related type that shares historical `SimpleUString` labels. This does not block the SSO layout's direct parent assignment because the two endpoint methods and class page now document the SSO side separately.

## Score Rationale

- Completion is `85` because the page now records endpoint helper behavior, exact offset roles, growth policy, large-allocation boundary behavior, one concrete static empty-object instance, separation from pointer-backed strings, live helper-boundary refresh, and a direct `SimpleUString` parent decision. It remains at the gate rather than higher because the final public class/API relationship to the `StringBase` family is still open.
- Confidence is `88` because the clear helper, counted-assign helper, SimpleUString/StringUtil owner pages, static-object memory page, and refreshed IDA helper metadata agree on the 24-byte empty/inline shape. Confidence remains below final confidence because the original source type name and representation split are not final.

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- [UID:0000WT][0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland](by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md)
- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md)
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md)

## Changes

- 2026-05-30: Existing layout evidence cited only raw endpoint addresses and the broad `0x00421310-0x004216cb` aggregate. Changed this to link the exact endpoint helper pages and warn that the aggregate middle is not layout evidence. Evidence: IDA MCP split of the mixed helper island and endpoint-helper decompilation.
- 2026-06-04: Marked `RECONSTRUCTABLE:TRUE` without changing scores.
  - Reasoning: the exact clear and counted-assign helper pages prove the 24-byte UTF-16 SSO-7 data layout as source-level structure information; parent attachment remains blank until this layout's relationship to the pointer-backed string family is resolved.
- 2026-06-07 A006 documentation pass:
  - Before: the page was `72/84` and mostly listed the two endpoint helpers.
  - After: raised to `78/86`.
  - Summary/evidence: added endpoint-helper operational details, capacity/length/growth semantics, aligned-allocation caveat, the `0x0066de18-0x0066de30` empty static-object instance, and the explicit boundary against the pointer-backed `StringBase`/ref-counted-header family.
- 2026-06-08 A006 Batch140 parent-gate update:
  - Before: `COMPLETION:78`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000D9`.
  - Summary/evidence: live IDA reconfirmed the exact clear and counted-assign helper sizes and callee sets. The direct owner is the [UID:0000D9][SimpleUString](by-class/SimpleUString.md) class/facade page, which was separately raised to `85/87` for SSO-specific parent evidence; [UID:0000OA][StringBase](by-file/StringBase.md) remains excluded for this SSO object layout.
