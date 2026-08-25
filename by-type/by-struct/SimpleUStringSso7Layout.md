*** UID:0001W5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000D9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000D9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// SimpleUString SSO-7 layout evidence is emitted by the SimpleUString class
// declaration; this page records offset and storage-policy proof only and
// should not emit a duplicate struct.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SimpleUStringSso7Layout

## Status

- Entity kind: inferred struct/layout
- Direct owner: [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- File parent through class: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Proposed header: `util/StringUtil.h`
- Confidence: very strong for the exact 24-byte SSO-7 layout, concrete static-instance bytes/lifetime, endpoint helpers, and `SimpleUString` class parent; medium-high for the original lexical relationship to the later pointer-backed family.
- Reconstructable: true as source-level string-layout evidence; the formal block now carries a no-duplicate layout comment because the emitted declaration lives on [UID:0000D9][SimpleUString](by-class/SimpleUString.md).

## Direct Parent Decision

`AUTOGEN_PARENT_UID` is set to [UID:0000D9][SimpleUString](by-class/SimpleUString.md). The child layout now clears the corrected `85/85` gate, and Batch140 raised the class parent to `85/87` with SSO-specific parent evidence. The direct owner is the `SimpleUString` class/facade page because this is an object layout with class methods at `0x00421310` and `0x00421590`; the broader file parent remains [UID:0000OB][StringUtil](by-file/StringUtil.md). Do not attach this SSO layout directly to [UID:0000OA][StringBase](by-file/StringBase.md), which owns the separate pointer-backed ref-counted layout.

## Recovered Layout

The early `SimpleUString` helper pair and concrete UID00027J static object use an exact 24-byte UTF-16 small-string layout with inline space for seven characters plus terminator:

| Offset | Size | Field | Notes |
| --- | --- | --- | --- |
| `0x00` | `0x10` | `m_inlineBuffer[8]` / `m_heapBuffer` union | Inline buffer is used when capacity is `<= 7`; otherwise the first dword is a heap pointer. Names are deterministic source-facing inferences. |
| `0x10` | `0x04` | unsigned `m_length` | Counted wide characters, excluding terminator. |
| `0x14` | `0x04` | unsigned `m_capacity` | Inline capacity is `7`; heap capacity uses the documented growth policy. |

## Evidence

- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) is now the concrete formal `SimpleUString::Clear()` proof for this layout. Current MCP session `80de0a67` confirms it frees `heapBuffer` only when `capacity >= 8`, computes `(capacity + 1) * sizeof(wchar_t)` as the deallocation size, validates the large-allocation header for byte sizes `>= 0x1000`, passes the adjusted pointer/size to the free wrapper, then writes `length = 0`, `capacity = 7`, and `inlineBuffer[0] = 0`.
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) is now the concrete formal `SimpleUString& SimpleUString::Assign(const wchar_t *source, unsigned int length)` proof for assigning counted UTF-16 input into this layout. Current MCP session `80de0a67` confirms exact range `0x00421590-0x004216cb`, size `0x13b` / 315 bytes (Verified with `int_convert.py`), SHA16 `2e2b7de08fe03fe5`, twelve-byte predecessor padding, five-byte successor padding, `+0x10` length writes, `+0x14` capacity reads/writes, `+0x00` heap/inline union use, return-this normal exits, `length | 7` plus 1.5x growth, `0x7ffffffe` cap, old heap release, 74 code xrefs, no data xrefs, and no VA/RVA pointer route.
- [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) is the current proof that the same SSO-7 layout supports narrow-byte to UTF-16 append/grow. B003 MCP session `80de0a67` confirms exact range `0x00423060-0x00423204`, size `0x1a4` / 420 bytes, SHA16 `7cd41a67bc199b3f`, four-byte predecessor padding, twelve-byte successor padding, two code refs, zero data refs, no VA/RVA pointer route, sign-extended source-byte writes, `+0x10` length, `+0x14` capacity, inline threshold `8`, inline capacity `7`, `(length + 1) | 7` plus 1.5x growth, allocator `0x00423d00`, free wrapper `0x005c7526`, cleanup helper `0x00421310`, and large-allocation `0x1000`/`+0x23`/`0x1f` validation. It stays blank-C++ because the exact helper has an unused third stack argument and is an internal range/tag append body.
- The historical [UID:0000WT][0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland](by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md) aggregate is mixed; the middle functions are not layout evidence for this struct.
- Metadata explicitly calls this the UTF-16 SSO-7 subcluster.
- 2026-06-08 Batch140 live IDA refresh reconfirmed `0x00421310` as `sub_421310` size `0x52` and `0x00421590` as `sub_421590` size `0x13b`. The clear helper still calls the allocator-free path plus invalid-parameter support, while the assign helper still calls allocation, `memmove`, string-too-long support, free, and invalid-parameter support.

## Operational Model

- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) treats `+0x14` as the capacity gate. Values below `8` mean the object starts with inline UTF-16 storage; values `>= 8` mean `+0x00` is a heap pointer that must be released before resetting to the empty inline state.
- In the `+0x14 >= 8` path, [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) preserves the same large-allocation convention later used by growth helpers: caller-side byte size `(capacity + 1) * 2`, `0x1000` threshold, raw allocation pointer at the dword before the aligned user pointer, `0x23` size adjustment on the raw-pointer free path, and invalid-parameter abort if the header delta exceeds `0x1f`.
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) treats `+0x10` as the current length, compares the requested counted UTF-16 length against `+0x14`, writes the terminator after `length` code units, and uses the same heap/inline split when growing. Its formal `Assign` block keeps the return value as `*this`, matching the `mov eax, edi` / `retn 8` exits; this return shape strengthens method-level source quality but does not add fields to the 24-byte layout.
- [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) treats the same object as a destination for a half-open narrow-byte source range. It sign-extends each byte before writing a UTF-16 code unit, terminates after the appended character, and grows using the same allocation/free policy. The target's formal block now carries a no-standalone-source comment because the binary `retn 0x0c` helper cleans an unused third stack argument; the field/layout evidence is strong, but the exact source method signature would be synthetic.
- The growth path rounds the requested length with an `| 7` style capacity floor and checks a 1.5x growth candidate before allocating `(capacity + 1) * sizeof(wchar_t)` bytes. That confirms the capacity is counted in UTF-16 code units, not raw bytes.
- Large heap strings use an aligned-allocation header validation path before free. That behavior belongs to the storage helper policy; it does not add fields inside this 24-byte object.
- The member names in emitted child code (`m_heapBuffer`, `m_inlineBuffer`, `m_length`, `m_capacity`) are source-facing inferences from this repeated field behavior, not proven original symbols. The offsets and lifetime roles are confirmed; spelling remains a confidence caveat.

## Static Instance Evidence

[UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md) is the primary concrete static instance for this layout:

| Range | Layout role |
| --- | --- |
| `0x0066daec-0x0066dafc` | zeroed inline storage / heap-pointer union |
| `0x0066dafc-0x0066db00` | unsigned length initialized to `0` |
| `0x0066db00-0x0066db04` | unsigned capacity initialized to `7` |

Live reanalysis records 33 whole-object references, 12 length references, 12 capacity references, and no interior references inside the `0x10`-byte union. Its compiler startup wrapper applies the shared empty wide literal with count zero and registers cleanup. The cleanup conditionally frees heap storage, validates the large-allocation header path, and restores inline NUL, length zero, and capacity seven. These facts prove both the loader representation and runtime static-lifetime use of the layout.

[UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md) is an independent static object with the same empty SSO shape:

| Range | Layout role |
| --- | --- |
| `0x0066de18-0x0066de28` | zeroed inline storage / pointer-or-inline union |
| `0x0066de28-0x0066de2c` | length field initialized to `0` |
| `0x0066de2c-0x0066de30` | capacity field initialized to `7` |

That page keeps ownership under MetaMan because the object is used as metadata lookup state, but its initialized bytes and matching shared-empty/count-zero startup lowering independently support this layout and bare default-construction source shape.

## Saved IDA Compatibility Types

- Supervisor Gate 2B catalog entry `0360` created IDA union `SimpleUStringSso7Storage`, exact size `0x10`, with `wchar_t m_inlineBuffer[8]` and `wchar_t *m_heapBuffer` at offset zero.
- It also created IDA struct `SimpleUStringSso7`, exact size `0x18`, with `SimpleUStringSso7Storage m_storage` at `+0x00`, `unsigned int m_length` at `+0x10`, and `unsigned int m_capacity` at `+0x14`.
- `[0x0066daec,0x0066db04)` is now one item of that struct type named `g_emptySimpleUString`. IDA automatically used intermediate name `stru_66DAEC` during consolidation before the accepted final rename; the intermediate name is historical tooling state, not source evidence.
- Existing IDA ordinal 835 `SimpleUString` remains size four and unchanged. The new compatibility types are an IDA ABI view only; reconstructed human source continues to use the project-facing class declaration emitted by [UID:0000D9][SimpleUString](by-class/SimpleUString.md).
- Target/member xrefs remain `33/0/0/0/12/12`, and all object bytes, neighboring fences, wrapper ranges, helper bytes, and shared literal were preserved. Catalog0360's UID00027J checkpoint `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, prestate backup `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`, unrelated UID0001HA checkpoint `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, and later `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69` checkpoint are historical. Bounded read-only MCP and byte/xref/type readback found no UID00027J drift after the newest shared save; the current authoritative shared IDB is SHA256 `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, saved `2026-07-29T14:22:15.9735862-04:00`.

## Boundary Against Pointer-Backed Strings

- Keep this layout separate from [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md) and [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md). The SSO-7 object embeds its short UTF-16 buffer in the first 16 bytes and stores length/capacity at `+0x10/+0x14`; the pointer-backed family stores a data pointer to a ref-counted header at `data[-3..-1]`.
- [UID:0000D9][SimpleUString](by-class/SimpleUString.md) and [UID:0000OB][StringUtil](by-file/StringUtil.md) use this page as the exact SSO-side layout anchor. The separate pointer-backed `StringBase` family remains outside this layout; unresolved broader lexical/API history does not weaken these offsets or UID00027J's class/source disposition.

## 2026-07-01 B007 No-Duplicate Source Disposition

The accepted implementation callback keeps this page as offset/storage evidence only. The emitted source declaration now lives on [UID:0000D9][SimpleUString](by-class/SimpleUString.md), so a second generated struct here would duplicate the same SSO-7 storage model and weaken ownership.

## Open Questions

- The stripped binary cannot prove whether the SSO-7 and pointer-backed families were separate original template instantiations or related facades sharing historical labels. This bounded whole-family lexical question does not block the exact SSO-7 layout, direct parent, class formal, static global, or compatibility-UDT disposition.

## Score Rationale

- Completion is `90` because the page records endpoint and append helper behavior, exact union/length/capacity fields, growth and large-allocation policy, two static empty objects, UID00027J loader/runtime/cleanup proof, saved compatibility UDTs, separation from pointer-backed strings, direct `SimpleUString` parent, and the no-duplicate formal disposition. It remains below final only because the broader historical public class/API relationship to `StringBase` is outside scope.
- Confidence is `93` because clear/assign/append helpers, concrete bytes and xrefs, startup/cleanup behavior, sibling static-object lowering, class/file owners, and catalog0360 saved IDA readback agree on the exact 24-byte empty/inline shape. Original lexical type/member spelling remains a bounded confidence cap.

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- [UID:0000WT][0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland](by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md)
- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md)
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md)
- [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md)

## Changes

- 2026-07-29 B004 UID00027J ordinary implementation and saved-IDA reconciliation:
  - Raised `86/89 -> 90/93`; owner `0000D9`, emitter route, reconstructable state, and formal no-duplicate CPP/blank H remain unchanged.
  - Replaced tentative layout wording with exact union/unsigned-length/unsigned-capacity roles and added UID00027J bytes, 33/12/12 xrefs, startup/cleanup behavior, matching static-object lowering, source-facing field-name disposition, and pointer-backed-family boundary.
  - Recorded catalog0360's exact `0x10` union, `0x18` struct, consolidated data item, automatic `stru_66DAEC` intermediate normalization, protected size-four `SimpleUString` UDT, unchanged bytes/xrefs, and durable saved-IDB identity.
- 2026-07-01 B007 [UID:0000OB][StringUtil](by-file/StringUtil.md) implementation callback: raised score to `86/89` and inserted the accepted formal no-duplicate layout comment pointing to the `SimpleUString` class declaration.
- 2026-06-24 B003 [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) source-quality sync:
  - Changed to: support wording only; scores remain `85/88`.
  - Summary/evidence: added [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) as current proof that the SSO-7 `+0x00/+0x10/+0x14` layout also supports narrow-byte to UTF-16 append/grow. MCP session `80de0a67` confirms exact `0x1a4` / 420-byte range, SHA16 `7cd41a67bc199b3f`, padding, two code refs, zero data refs, no pointer route, sign-extension of source bytes, inline threshold `8`, inline capacity `7`, capacity growth, allocator/free/cleanup policy, and large-allocation validation. The layout evidence is accepted, while the exact target's formal C++ remains blank because the helper has an unused third stack argument and is an internal range/tag append body.
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
- 2026-06-24 B005 [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) source-quality sync:
  - Changed to: support wording only; scores remain `85/88`.
  - Summary/evidence: updated [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) as the formal `SimpleUString::Clear()` proof for the SSO-7 layout. Current MCP session `80de0a67` confirms exact `0x52` range, `+0x14` capacity gate, `+0x00` heap/inline union, `+0x10` length reset, empty capacity `7`, inline UTF-16 NUL write, size-aware free wrapper call, large-allocation header validation, 83 code xrefs across 22 functions, zero data xrefs, and no pointer-table route. Field names remain inferred but are now stable enough for the exact child C++ block.
- 2026-06-24 B003 [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) source-quality sync:
  - Changed to: support wording only; scores remain `85/88`.
  - Summary/evidence: updated [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) as the formal `SimpleUString& SimpleUString::Assign(const wchar_t *source, unsigned int length)` proof for assigning counted UTF-16 strings into the SSO-7 layout. MCP session `80de0a67` confirms exact `0x13b` / 315-byte range (Verified with `int_convert.py`), SHA16 `2e2b7de08fe03fe5`, `+0x00/+0x10/+0x14` field roles, inline threshold `8`, inline capacity `7`, capacity growth by `length | 7` plus a 1.5x old-capacity candidate, `0x7ffffffe` cap, `(capacity + 1) * sizeof(wchar_t)` allocation/free sizing, large-allocation `0x1000`/`+0x23`/`0x1f` handling, 74 code xrefs, zero data xrefs, and no VA/RVA pointer route. Field and helper names remain inferred source-facing names, but this is a confidence cap rather than a no-code blocker for the exact child.
