*** UID:0000OA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StringBase

## Status

- Proposed module: `util/StringBase.cpp`
- Proposed header: `util/StringBase.h` or `util/StringUtil.h`
- Confidence: high for `StringBase.cpp` as the direct source root for the ref-counted `0x00582500-0x00584d7d` string-buffer implementation; medium for exact original header/API spelling.
- Source-placement caveat: older recovered ownership mixed this string-buffer family with `LObject` and `SimpleUString` views. Current IDA behavior, compiler metadata names, exact string-helper memory aggregates, and the proposed source tree now make this file the direct parent for the ref-counted buffer implementation, while [UID:0000OB][StringUtil](by-file/StringUtil.md) remains the broader utility-string coordinator.
- Primary template/type doc: [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- Evidence basis: existing by-memory/by-type/by-global documentation plus IDA MCP lookup, decompile, caller, callee, xref, and padding checks recorded below.

## File Role

This is the preferred source-structure home for the ref-counted ANSI/UTF-16 string implementation historically tracked under [UID:0000KV][LObject](by-file/LObject.md). The older owner is polluted: the real `LObject` class is a tiny virtual base/runtime object, while the string methods use field `0x00` as a character-data pointer with a 12-byte header immediately before it.

The original project may have put this in `StringUtil.cpp`, but the recovered template type name `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` is strong enough to track a dedicated `StringBase` module candidate.

## Likely Contents

| Entity | Address/range | Role |
| --- | --- | --- |
| `mystr::StringBase<char, mystr::mychar_traits<char>>` helpers | `0x00582500-0x00583206`, selected `0x005832f0+` methods | ANSI construction, assignment, copy-on-write, allocation, release, append, formatting, and mutation helpers. |
| `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` helpers | `0x00582500-0x00584d7d`, especially `0x00583280`, `0x00583840`, `0x005840f0`, `0x005845b0` | UTF-16 construction, formatting, comparison, search, splice, trim, and substring helpers. |
| [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) | data pointer `-0x0c` through `-0x04` | Shared header with `refCount`, `length`, and `capacity`. |
| [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) | `0x00670278`, `0x00670290`, `0x0069bacc-0x0069bbe4` | Empty-string sentinels and 64/128/256/512 fixed-capacity pools for wide and ANSI buffers. |
| pointer-backed formatting wrappers/workers | [UID:0002LJ][0x00583210-0x00583273.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md), [UID:0002LK][0x00583280-0x005832e3.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md), [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md), [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md) | ANSI/UTF-16 format constructors and `va_list` workers; likely `StringBase<char/wchar_t>` helpers or a thin string facade over them. |
| pointer-backed wide literal append wrapper | [UID:000325][0x004671b0-0x004671de.StringBaseAppendWideLiteral](by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md) | Small UTF-16 literal append/count helper emitted near Application callback/destructor support but implemented as a call into the shared wide StringBase append routine. |
| pointer-backed compare helpers | [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md), [UID:0002LO][0x005845b0-0x005845ec.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md) | UTF-16 range comparator and literal compare wrapper. |
| [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md) | `0x005151b0`, `0x005151d0` | Thin default-codepage conversion wrappers consumed by the string constructors/converters. |

## Evidence

- Existing `LObject`, `StringBaseTemplate`, string-buffer layout, and string-pool docs distinguish a true virtual base object from the ref-counted string-buffer family; this file records the source-structure consequence of that split.
- IDA decompilation of `0x004f4a80` is a 9-byte constructor that writes only `LObject::vftable`, while IDA decompilation of `0x00582d80` and `0x00582e30` writes a data pointer, allocates an inline header, stores `refCount`, `length`, and `capacity`, and returns `header + 0x0c`.
- IDA decompilation of `0x00583210` seeds the object with the ANSI empty sentinel `0x00670290` and forwards to the ANSI formatting worker at `0x00583720`.
- IDA decompilation of `0x00583280` seeds the object with the wide empty sentinel `0x00670278` and forwards to the wide formatting worker at `0x00583840`.
- Exact split pages now document the two constructor wrappers, the ANSI/UTF-16 formatting workers, the UTF-16 range comparator, and the literal comparison wrapper. These were verified with IDA MCP `lookup_funcs`, `decompile`, `callers`, `callees`, sentinel xrefs, and byte-level padding checks on 2026-05-31.
- IDA decompilation of `0x005833a0` releases wide storage through `InterlockedDecrement`, returns 64/128/256/512 buckets to the matching pool globals, and otherwise heap-frees the 12-byte-prefixed allocation.
- IDA decompilation of `0x005845b0` compares `this->m_data` to a wide literal by reading the stored length from `m_data[-2]` and forwarding to the range comparator at `0x005840f0`.
- 2026-06-10 B001-014 IDA MCP split of [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) found [UID:000325][0x004671b0-0x004671de.StringBaseAppendWideLiteral](by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md): the function measures a UTF-16 source with `wcslen` and calls shared append helper `0x00584470`. Its only direct caller found in this pass is Application OS-string setup at `0x0046509f`, which is a consumer; the callee and behavior make this file the best direct source owner.
- IDA decompilation of `0x0052a460` resets a callback object's vtable to `FunctionObjectT<mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>>::vftable`, preserving the `mystr::StringBase` type spelling in compiler metadata.
- Caller checks show `0x00583280` has broad fan-in from application initialization, browser/path helpers, UI, audio, and security integration. This breadth supports utility-string ownership, not any one feature module.
- 2026-06-08 A006 Batch135 live IDA MCP parent-gate refresh reconfirmed the key boundary and ownership facts: `0x004f4a80` is only a 9-byte true `LObject` shell constructor; `0x00582d80` and `0x00582e30` are the ANSI/wide buffer allocators with sizes `0xac` and `0xb2`; `0x005832f0` and `0x005833a0` are the release twins with sizes `0xa2`; `0x00583720`, `0x00583840`, `0x005840f0`, and `0x005845b0` remain the exact format/compare helpers with sizes `0x112`, `0x128`, `0x6a`, and `0x3c`.
- The same Batch135 refresh counted `23` direct refs to the wide sentinel `0x00670278`, `16` refs to the ANSI sentinel `0x00670290`, `8` refs to the trim whitespace pointer slot `0x0067027c`, and `4` refs each to the eight string pool storage records from `0x0069bacc` through `0x0069bbe4`.
- IDA `list_globals` with `*StringBase*`/`*mystr*` returned the preserved compiler names for `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` vtables and RTTI records at `0x0061fcd4`, `0x0061fcec`, `0x0061ff70`, `0x0062004c`, `0x00620094`, `0x00622cf4`, and related `0x0064c6xx-0x0064caxx` RTTI entries.

## Exclusions

- Keep [UID:0000KV][LObject](by-file/LObject.md) limited to the runtime/base shell around `0x004f4a80-0x004f4c0d`.
- Keep FolderTreePane traversal callbacks around `0x004b3400-0x004b3d41` with [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), not with this file.
- Keep `FunctionObjectT<mystr::StringBase<...>>` destructor support with [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md). The string type parameter is evidence for the string type name, not ownership of callback template code.
- Keep the early SSO-7 layout at `0x00421310-0x004216cb` under [UID:0000OB][StringUtil](by-file/StringUtil.md) / [UID:0000D9][SimpleUString](by-class/SimpleUString.md) until a later pass proves whether it is a separate string class or another `StringBase` representation.
- Keep [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) out of `StringBase` ownership. The helper pair calls this file's string-helper family, but B001-021 identifies the primary receiver as the [UID:00004V][File](by-class/File.md) stream interface; `StringBase` is a destination string dependency, not the direct source owner.

## 2026-06-08 Virtual Readable Helper Audit

- A009 checked [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) as a plausible `StringBase`-adjacent source candidate because the two helpers call `0x00582a80`, `0x00582c60`, `0x00584540`, `0x00582b30`, `0x00582500`, `0x00582b70`, `0x005834c0`, and `0x00584020`.
- B001-021 supersedes that candidate-owner hypothesis: both helper bodies dispatch through virtual slots (`+0x14`, `+0x1c`, `+0x20`, and `+0x24`) that live IDA maps to the File/DATFile/StdioFile stream contract. The correct direct owner is [UID:00004V][File](by-class/File.md), while this file remains a callee/dependency.
- At the time of the A009 virtual-readable audit, the score stayed at `88/80` because that unrelated helper pair did not prove a direct source owner. Batch135 later raised this page to `88/86` for the core ref-counted string-buffer family based on separate StringBase-specific evidence.

## 2026-06-08 String Family Parent-Gate Audit

A006 rechecked the direct parent question for [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md), [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md), and [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md). The direct source parent is this `StringBase` file page:

- The exact executable string family [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md), [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md), and [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md) is already documented as `StringBase.cpp` source code rather than true `LObject` code.
- The global sentinels, trim whitespace pointer, and eight small-buffer pool objects are consumed by the alloc/release/trim helpers inside that same family. `PoolAllocator.cpp` owns the allocator mechanics, but not the string-specific static declarations.
- [UID:0000OB][StringUtil](by-file/StringUtil.md) remains a valid utility-string umbrella, but it explicitly delegates the ref-counted ANSI/UTF-16 implementation to this file. [UID:0000D9][SimpleUString](by-class/SimpleUString.md) is a facade/representation coordination page, not the direct source root for this buffer core.
- The score is raised from `88/80` to `88/86`: completion is unchanged because final public API names and header spelling are still open, but confidence now clears the corrected parent gate based on live IDA counts, compiler metadata names, source-tree placement, and exact child aggregate attachments.

## Migration Notes

For source reconstruction, do not bulk-merge the older LObject-owned string subset into `LObject.cpp`. A safer target split is:

```text
util/LObject.cpp
  LObject virtual base/runtime shell only

util/StringBase.cpp
  0x00582500-0x00584d7d ref-counted ANSI/UTF-16 string-buffer family

util/PoolAllocator.cpp
  fixed-block allocator mechanics used by StringBase pool globals

ui/controls/FolderTreePane.cpp
  tree traversal/search callbacks currently misattributed to LObject
```

The final header can still collapse into `StringUtil.h` if later original-source evidence favors a flatter utility-string file, but source migration should treat `StringBase` as the preferred owner for the `0x00582500+` family.

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000KV][LObject](by-file/LObject.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)
- [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md)
- [UID:0002LJ][0x00583210-0x00583273.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md)
- [UID:0002LK][0x00583280-0x005832e3.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md)
- [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md)
- [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md)
- [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md)
- [UID:0002LO][0x005845b0-0x005845ec.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md)
- [UID:000325][0x004671b0-0x004671de.StringBaseAppendWideLiteral](by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md)
- [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md)
- [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md)
- [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md)
- [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)

## Changes

- 2026-06-10 B001-014 append helper split:
  - Score unchanged at `88/86`.
  - Added [UID:000325][0x004671b0-0x004671de.StringBaseAppendWideLiteral](by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md) as a small direct child of this file.
  - Evidence: IDA MCP confirms the helper calls `wcslen` and shared StringBase append routine `0x00584470`; Application setup is only the observed caller/consumer.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `78`.
  - Evidence: document captures the polluted `LObject` split, likely string-template contents, ref-counted buffer layout, sentinel/pool globals, IDA decompilation evidence, exclusions, migration split, and cross-references; confidence is capped by final source-file name and unresolved relationship to the earlier SSO/string utility representation.

- 2026-05-31: Added exact pointer-backed formatting/compare child pages and projected the file to `NexusTK/util/`.
  - Before: pointer-backed wrappers were listed only as raw addresses and the validator-managed projected reconstruction path was blank.
  - After: linked exact child memory pages, raised scores modestly to `88/80`, and set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` so the validator stages an empty `StringBase.cpp`.
  - Evidence: IDA MCP verification of `0x00583210`, `0x00583280`, `0x00583720`, `0x00583840`, `0x005840f0`, and `0x005845b0`; final C++ remains intentionally blank because the family is below the `95+` reconstruction-code gate.

- 2026-06-03: updated the ANSI and wide formatting worker child links to corrected half-open IDA ranges `0x00583720-0x00583832` and `0x00583840-0x00583968`; no file-level score change.

- 2026-06-06: removed stale recovered-source provenance from the file-level evidence.
  - Before: status, evidence, and migration notes described the split through stale recovered-source wording.
  - After: kept the existing `88/80` score and `NexusTK/util/` path while making the evidence basis explicit: existing project documentation plus recorded IDA lookup/decompile/caller/callee/xref/padding checks.
  - Evidence: the documented split still rests on the compact `LObject` constructor, the `0x00582500+` ref-counted buffer family, sentinel/pool globals, `StringBaseTemplate` type-name evidence, and linked exact child memory pages.
- 2026-06-08 A009 Batch117 candidate-source audit, superseded by 2026-06-10 B001-021:
  - Changed to: documentation only; scores remain `88/80`.
  - Summary/evidence: checked [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) as a plausible `StringBase`-adjacent candidate because of shared string-helper callees. B001-021 later rejected direct `StringBase` ownership because the virtual receiver is now IDA-mapped to the File stream interface.
- 2026-06-08 A006 Batch135 parent-gate repair:
  - Before: `COMPLETION:88`, `CONFIDENCE:80`.
  - After: `COMPLETION:88`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA reconfirmed the true `LObject` shell is only `0x004f4a80-0x004f4a89`, while the `0x00582500-0x00584d7d` family has exact StringBase allocation/release/format/compare helper boundaries, sentinel and pool xref counts, and preserved `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` compiler metadata. This clears the corrected `85/85` parent gate for the string-buffer global/type pages while leaving final header/API spelling below final-source confidence.
